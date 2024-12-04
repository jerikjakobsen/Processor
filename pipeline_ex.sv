module pipeline_ex
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64
)
(
    input wire clk,
    input wire reset,

    output wire ready,
    input wire next_stage_ready,
    output wire jump_signal,
    output wire [ADDR_WIDTH-1:0] jump_pc,
    
    input wire [6:0] opcode,
    input wire [3:0] branch_type,
    input wire [ADDR_WIDTH-1:0] instruction_pc,
    input wire [DATA_WIDTH-1:0] r1_val,
    input wire [DATA_WIDTH-1:0] r2_val,
    input wire signed [DATA_WIDTH-1:0] imm,
    input wire [4:0] dst_reg,
    input wire imm_or_reg2,
    input wire [31:0] mem_opcode,
    input wire [3:0] mem_operation_size,
    input wire is_word_op,
    input wire [2:0] unsigned_op,
    output wire [DATA_WIDTH-1:0] ex_res,
    output wire [DATA_WIDTH-1:0] r2_val_mem,
    output wire [4:0] mem_dst_reg,
    output wire [31:0] next_mem_opcode,
    output wire [2:0] next_mem_operation_size,
    input wire ecall,
    output wire ecall_mem
);

  parameter NOP = 4'd0,
            ADD = 4'd1,
            SUB = 4'd2,
            OR = 4'd3,
            AND = 4'd4,
            XOR = 4'd5,
            MUL = 4'd6,
            MULH = 4'd7,
            DIV = 4'd8,
            REM = 4'd9,
            SHIFT_LEFT = 4'd10,
            SHIFT_RIGHT = 4'd11,
            SET_LESS_THAN = 4'd12,
            JUMP = 4'd13,
            PC_ADD = 4'd14,
            LOAD_REGISTER = 4'd15;
  
  parameter BEQ  = 3'b000,
            BNE  = 3'b001,
            BLT  = 3'b010,
            BGE  = 3'b011,
            JAL = 3'b110,
            JALR = 3'b111;
  
  logic [63:0] operand2, temp_result;
  logic [127:0] multiplication_result;
  assign operand2 = (imm_or_reg2) ? imm : r2_val;

  logic tmp_signal;
  assign tmp_signal = instruction_pc == 63'h22f9c;

  always_comb begin
    ready = (opcode == 0 || next_stage_ready);
    next_mem_opcode = mem_opcode;
    next_mem_operation_size = mem_operation_size;
    mem_dst_reg = dst_reg;
    r2_val_mem = r2_val;
    ecall_mem = ecall;

    jump_signal = 0;
    jump_pc = 64'd0;
    ex_res = 64'd0;
    
    case(opcode)
      ADD: begin
        jump_signal = 0;
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] + operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val + operand2;
        end
      end
      
      SUB: begin
        jump_signal = 0;
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] - operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val - operand2;
        end
      end
      
      AND: begin
        jump_signal = 0;
        ex_res = r1_val & operand2;
      end

      OR: begin
        jump_signal = 0;
        ex_res = r1_val | operand2;
      end

      XOR: begin
        jump_signal = 0;
        ex_res = r1_val ^ operand2;
      end

      SHIFT_LEFT: begin
        jump_signal = 0;
        if(is_word_op) begin
          temp_result = r1_val[31:0] << operand2;
          ex_res = $signed(temp_result[31:0]);
        end else begin
          ex_res = r1_val << operand2;
        end
      end
      
      SHIFT_RIGHT: begin
        jump_signal = 0;
        if(is_word_op) begin
          if(unsigned_op == 1) begin
            ex_res = {{32{1'b0}}, (r1_val[31:0] >> operand2)};
          end else begin
            if (r1_val[63]) begin
              // Sign-extend MSBs on right shift
              temp_result = (r1_val >> operand2) | ~((1 << (64 - operand2)) - 1);
            end else begin
              temp_result = r1_val >> operand2;
            end

            // temp_result = r1_val[31:0] >>> operand2;
            ex_res = $signed(temp_result[31:0]);
          end
        end else begin
          if(unsigned_op == 1) begin
            ex_res = r1_val >> operand2;
          end else begin
            if (r1_val[63]) begin
              // Sign-extend MSBs on right shift
              ex_res = (r1_val >> operand2) | ~((1 << (64 - operand2)) - 1);
            end else begin
              ex_res = r1_val >> operand2;
            end
            // ex_res = $unsigned($signed(r1_val) >>> operand2);
          end
        end
      end

      SET_LESS_THAN: begin
        jump_signal = 0;
        if(unsigned_op == 1) begin
          ex_res = $unsigned(r1_val) < $unsigned(imm) ? 1 : 0;
        end else begin
          ex_res = $signed(r1_val) < $signed(imm) ? 1 : 0;
        end
      end
      
      MUL: begin
        jump_signal = 0;
        if(is_word_op) begin
          temp_result = $signed(r1_val[31:0]) * $signed(operand2[31:0]);
          ex_res = {{32{temp_result[31]}}, temp_result[31:0]};
        end else begin
          multiplication_result = r1_val * operand2;
          ex_res = multiplication_result[63:0];
        end
      end

      MULH: begin
        jump_signal = 0;
        if(unsigned_op == 2) begin // MULHSU
          multiplication_result = $signed(r1_val) * $unsigned(operand2);
        end else if(unsigned_op == 1) begin // MULHU
          multiplication_result = $unsigned(r1_val) * $unsigned(operand2);
        end else begin // MULH
          multiplication_result = $signed(r1_val) * $signed(operand2);
        end
        ex_res = multiplication_result[127:64];
      end
      
      DIV: begin
        jump_signal = 0;
        if(operand2 != 0) begin
          if(is_word_op) begin
            if(unsigned_op == 1) begin
              temp_result = $unsigned(r1_val[31:0]) / $unsigned(operand2[31:0]);
              ex_res = {32'b0, temp_result[31:0]};
            end else begin
              temp_result = $signed(r1_val[31:0]) / $signed(operand2[31:0]);
              ex_res = $signed(temp_result[31:0]);
            end
          end else begin
            if(unsigned_op == 1) begin
              ex_res = $unsigned(r1_val) / $unsigned(operand2);
            end else begin
              ex_res = $signed(r1_val) / $signed(operand2);
            end
          end
        end else begin
          ex_res = 64'd0;
        end
      end

      REM: begin
        jump_signal = 0;
        if(operand2 != 0) begin
          if(is_word_op) begin
            if(unsigned_op == 1) begin
              temp_result = $unsigned(r1_val[31:0]) % $unsigned(operand2[31:0]);
              ex_res = {32'b0, temp_result[31:0]};
            end else begin
              temp_result = $signed(r1_val[31:0]) % $signed(operand2[31:0]);
              ex_res = $signed(temp_result[31:0]);
            end
          end else begin
            if(unsigned_op == 1) begin
              ex_res = $unsigned(r1_val) % $unsigned(operand2);
            end else begin
              ex_res = $signed(r1_val) % $signed(operand2);
            end
          end
        end else begin
          ex_res = 64'd0;
        end
      end

      LOAD_REGISTER: begin
        jump_signal = 0;
        ex_res = imm;
      end

      PC_ADD: begin
        jump_signal = 0;
        ex_res = instruction_pc + imm;
      end

      JUMP: begin
        case(branch_type)
          JAL: begin
            jump_signal = 1;
            jump_pc = instruction_pc + operand2;
            ex_res = instruction_pc + 4;
          end

          JALR: begin
            jump_signal = 1;
            jump_pc = r1_val + operand2;
            ex_res = instruction_pc + 4;
          end

          BEQ: begin
            if (r1_val == r2_val) begin
              jump_signal = 1;
              jump_pc = instruction_pc + imm;
            end
          end
          
          BNE: begin
            if (r1_val != r2_val) begin
              jump_signal = 1;
              jump_pc = instruction_pc + imm;
            end
          end
          
          BLT: begin
            if(unsigned_op == 1) begin
              if ($unsigned(r1_val) < $unsigned(r2_val)) begin
                jump_signal = 1;
                jump_pc = instruction_pc + imm;
              end
            end else begin
              if ($signed(r1_val) < $signed(r2_val)) begin
                jump_signal = 1;
                jump_pc = instruction_pc + imm;
              end
            end
          end
          
          BGE: begin
            if(unsigned_op == 1) begin
              if ($unsigned(r1_val) >= $unsigned(r2_val)) begin
                jump_signal = 1;
                jump_pc = instruction_pc + imm;
              end
            end else begin
              if ($signed(r1_val) >= $signed(r2_val)) begin
                jump_signal = 1;
                jump_pc = instruction_pc + imm;
              end
            end
          end

          default: begin
            jump_signal = 0;
          end
        endcase
      end

      default: begin
        jump_signal = 0;
        ex_res = 64'd0;
      end
    endcase
  end

endmodule
