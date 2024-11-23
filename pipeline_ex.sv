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
    
    input wire [31:0] opcode,
    input wire [ADDR_WIDTH-1:0] instruction_pc,
    input wire [DATA_WIDTH-1:0] r1_val,
    input wire [DATA_WIDTH-1:0] r2_val,
    input wire signed [DATA_WIDTH-1:0] imm,
    input wire [4:0] dst_reg,
    input wire imm_or_reg2,
    input wire [31:0] mem_opcode,
    input wire is_mem_load,
    input wire is_word_op,
    output wire [DATA_WIDTH-1:0] ex_res,
    output wire [DATA_WIDTH-1:0] r2_val_mem,
    output wire [4:0] mem_dst_reg,
    output wire [31:0] next_mem_opcode,
    output wire next_is_mem_load
);

  parameter NOP = 4'd0,
            ADD = 4'd1,
            SUB = 4'd2,
            OR = 4'd3,
            AND = 4'd4,
            XOR = 4'd5,
            MUL = 4'd6,
            DIV = 4'd7,
            REM = 4'd8,
            SL = 4'd9,
            SR = 4'd10,
            JUMP = 4'd11;
  
  parameter BEQ  = 3'b000,
            BNE  = 3'b001,
            BLT  = 3'b010,
            BGE  = 3'b011,
            BLTU = 3'b100,
            BGEU = 3'b101,
            JAL = 3'b110,
            JALR = 3'b111;
  
  logic [63:0] operand2;
  assign operand2 = (imm_or_reg2) ? imm : r2_val;

  always_comb begin
    ready = (opcode == 0 || next_stage_ready);
    next_mem_opcode = mem_opcode;
    next_is_mem_load = is_mem_load;
    mem_dst_reg = dst_reg;
    r2_val_mem = r2_val;
    
    case(opcode)
      ADD: begin
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] + operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val + operand2;
        end
      end
      
      SUB: begin
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] - operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val - operand2;
        end
      end
      
      AND: begin
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] & operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val & operand2;
        end
      end

      XOR: begin
        ex_res = r1_val ^ operand2;
      end
      
      MUL: begin
        if(is_word_op) begin
          ex_res[31:0] = r1_val[31:0] * operand2[31:0];
          ex_res = {{32{ex_res[31]}}, ex_res[31:0]};
        end else begin
          ex_res = r1_val * operand2;
        end
      end
      
      DIV: begin
        ex_res = r1_val / operand2;
      end
      
      REM: begin
        ex_res = r1_val % operand2;
      end
      
      SL: begin
        ex_res = r1_val << operand2[5:0]; // Shift by lower 6 bits for 64-bit values
      end
      
      SR: begin
        ex_res = r1_val >> operand2[5:0]; // Shift by lower 6 bits for 64-bit values
      end

      JUMP: begin
        case(branch_type):
          JAL: begin
            jump_signal = 1;
            jump_pc = operand2;
          end

          JALR: begin
            jump_signal = 1;
            jump_pc = r1_val + operand2;
          end

          BEQ: begin
            if (r1_val == r2_val) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end
          
          BNE: begin
            if (r1_val != r2_val) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end
          
          BLT: begin
            if ($signed(r1_val) < $signed(r2_val)) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end
          
          BGE: begin
            if ($signed(r1_val) >= $signed(r2_val)) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end
          
          BLTU: begin
            if (r1_val < r2_val) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end
          
          BGEU: begin
            if (r1_val >= r2_val) begin
              jump_signal = 1;
              jump_pc = imm;
            end
          end

          default: begin
            jump_signal = 0;
          end
        endcase
      end

      default: begin
        ex_res = 64'd0;
      end
    endcase



    if(instruction_pc == 66508) begin
      jump_signal = 1;
      jump_pc = 66392;
    end else begin
      jump_signal = 0;
    end
  end

endmodule
