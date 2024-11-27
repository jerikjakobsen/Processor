module pipeline_decode
#(
  ADDR_WIDTH = 64,
  DATA_WIDTH = 64
)
(
    input wire clk,
    input wire reset,
    output wire ready,
    input wire next_stage_ready,
    input wire [(DATA_WIDTH/2)-1:0] instruction,
    input wire [ADDR_WIDTH-1:0] instruction_pc,
    output wire [ADDR_WIDTH-1:0] next_stage_pc,
    output wire [6:0] ex_opcode,
    output wire [3:0] branch_type,
    output wire [4:0] r1_reg,
    output wire [4:0] r2_reg,
    output wire [4:0] dst_reg,
    output wire signed [DATA_WIDTH-1:0] imm,
    output wire is_word_op,
    output wire imm_or_reg2,
    output wire [6:0] mem_opcode,
    output wire [3:0] mem_operation_size,
    output wire ecall
);

  parameter IMM = 1'b1,
          REG2 = 1'b0;

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
            JUMP = 4'd11,
            PC_ADD = 4'd12,
            LOAD_REGISTER = 4'd13;
  
  parameter BEQ  = 3'b000,
            BNE  = 3'b001,
            BLT  = 3'b010,
            BGE  = 3'b011,
            BLTU = 3'b100,
            BGEU = 3'b101,
            JAL = 3'b110,
            JALR = 3'b111;

  parameter DOUBLE_WORD = 3'd0,
            WORD = 3'd1,
            HALF_WORD  = 3'd2,
            BYTE  = 3'd3,
            UNSIGNED_WORD = 3'd4,
            UNSIGNED_HALF_WORD  = 3'd5,
            UNSIGNED_BYTE  = 3'd6;

  logic [6:0] opcode;
  logic [2:0] funct3;
  logic [6:0] funct7;

  always_comb begin
    ready = (instruction == 0 || next_stage_ready);
    next_stage_pc = instruction_pc;
  end

  always_comb begin
    ecall = 0;
    if(instruction == 0) begin
      // NOP
      ex_opcode = 0;
    end else begin
      opcode = instruction[6:0];
      case (opcode)
        7'b0010011: begin
            funct3 = instruction[14:12];
            funct7 = instruction[31:25];
            mem_opcode = 3;

            case (funct3)
                3'b000: begin // ADDI
                  ex_opcode = ADD;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b010: begin // SLTI
                  ex_opcode = SL;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b011: begin // SLTIU
                  ex_opcode = SL;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b100: begin // XORI
                  ex_opcode = XOR;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b110: begin // ORI
                  ex_opcode = OR;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b111: begin // ANDI
                  ex_opcode = AND;
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b001: begin // SLLI
                  ex_opcode = SL;
                  imm_or_reg2 = IMM;
                  imm = instruction[24:20];
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                end
                3'b101: begin
                  case (funct7)
                    7'b0000000: begin // SRLI
                      ex_opcode = SR;
                      imm_or_reg2 = IMM;
                      imm = instruction[24:20];
                      dst_reg = instruction[11:7];
                      r1_reg = instruction[19:15];
                    end
                    7'b0100000: begin // SRAI
                      ex_opcode = SR;
                      imm_or_reg2 = IMM;
                      imm = instruction[24:20];
                      dst_reg = instruction[11:7];
                      r1_reg = instruction[19:15];
                    end
                  endcase
                end

                default: begin
                  dst_reg = 0;
                  ex_opcode = NOP;
                  r1_reg = 0;
                  r2_reg = 0;
                end
            endcase
        end

        7'b0011011: begin
          funct3 = instruction[14:12];
          funct7 = instruction[31:25];
          mem_opcode = 3;

          case(funct3)
            3'b000: begin // ADDIW
              ex_opcode = ADD;
              imm_or_reg2 = IMM;
              imm = {{52{instruction[31]}}, instruction[31:20]};
              dst_reg = instruction[11:7];
              r1_reg = instruction[19:15];
              is_word_op = 1;
            end
            3'b001: begin // SLLIW
              ex_opcode = SL;
              imm_or_reg2 = IMM;
              imm = instruction[24:20];
              dst_reg = instruction[11:7];
              r1_reg = instruction[19:15];
              is_word_op = 1;
            end
            3'b101: begin
              case (funct7)
                7'b0000000: begin // SRLIW
                  ex_opcode = SR;
                  imm_or_reg2 = IMM;
                  imm = instruction[24:20];
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                  is_word_op = 1;
                end
                7'b0100000: begin // SRAIW
                  ex_opcode = SR;
                  imm_or_reg2 = IMM;
                  imm = instruction[24:20];
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                  is_word_op = 1;
                end
              endcase
            end

            default: begin
              dst_reg = 0;
              ex_opcode = NOP;
              r1_reg = 0;
              r2_reg = 0;
            end
          endcase
        end

        7'b0111011: begin
          funct3 = instruction[14:12];
          funct7 = instruction[31:25];
          mem_opcode = 3;
          case(funct3)
            3'b000: begin
              dst_reg = instruction[11:7];
              r1_reg = instruction[19:15];
              r2_reg = instruction[24:20];
              imm_or_reg2 = REG2;
              is_word_op = 1;

              case(funct7)
                // ADDW
                7'b0000000: begin
                  ex_opcode = ADD;
                end

                // MULW
                7'b0000001: begin
                  ex_opcode = MUL;
                end

                // SUBW
                7'b0100000: begin
                  ex_opcode = SUB;
                end

                default: begin
                  dst_reg = 0;
                  ex_opcode = NOP;
                  r1_reg = 0;
                  r2_reg = 0;
                end
              endcase
            end 

            default: begin
              dst_reg = 0;
              ex_opcode = NOP;
              r1_reg = 0;
              r2_reg = 0;
            end
          endcase
        end

        7'b0110011: begin
          funct7 = instruction[31:25];
          funct3 = instruction[14:12];
          dst_reg = instruction[11:7];
          r1_reg = instruction[19:15];
          r2_reg = instruction[24:20];
          imm_or_reg2 = REG2;
          is_word_op = 0;
          mem_opcode = 3;

          case (funct7)
            7'b0000000: begin
              case (funct3)
                3'b000: ex_opcode = ADD;  // ADD
                3'b001: ex_opcode = SL;   // SLL
                3'b101: ex_opcode = SR;   // SRL
              endcase
            end
            7'b0100000: begin
              case (funct3)
                3'b000: ex_opcode = SUB;  // SUB
                3'b101: ex_opcode = SR;   // SRA
              endcase
            end
            7'b0000001: begin
              case (funct3)
                3'b000: ex_opcode = MUL;    // MUL
                3'b001: ex_opcode = MULH;   // MULH
                3'b010: ex_opcode = MULHSU; // MULHSU
                3'b011: ex_opcode = MULHU;  // MULHU
                3'b100: ex_opcode = DIV;    // DIV
                3'b101: ex_opcode = DIVU;   // DIVU
                3'b110: ex_opcode = REM;    // REM
                3'b111: ex_opcode = REMU;   // REMU
              endcase
            end
          endcase
        end

        7'b0111011: begin
          funct7 = instruction[31:25];
          funct3 = instruction[14:12];
          dst_reg = instruction[11:7];
          r1_reg = instruction[19:15];
          r2_reg = instruction[24:20];
          imm_or_reg2 = REG2;
          is_word_op = 1;
          mem_opcode = 3;

          case (funct7)
            7'b0000000: begin
              case (funct3)
                3'b000: ex_opcode = ADD; // ADDW
                3'b001: ex_opcode = SL;  // SLLW
                3'b101: ex_opcode = SR;  // SRLW
              endcase
            end
            7'b0100000: begin
              case (funct3)
                3'b000: ex_opcode = SUB; // SUBW
                3'b101: ex_opcode = SR;  // SRAW
              endcase
            end
            7'b0000001: begin
              case (funct3)
                3'b000: ex_opcode = MUL;   // MULW
                3'b100: ex_opcode = DIV;   // DIVW
                3'b101: ex_opcode = DIVU;  // DIVUW
                3'b110: ex_opcode = REM;   // REMW
                3'b111: ex_opcode = REMU;  // REMUW
              endcase
            end
          endcase
        end

        7'b0110111: begin
          // LUI
          ex_opcode = LOAD_REGISTER;
          dst_reg = instruction[11:7];
          imm_or_reg2 = IMM;
          imm = instruction[31:12];

          r1_reg = 0;
          r2_reg = 0;
          mem_opcode = 3;
        end

        7'b0010111: begin
          // AUIPC
          ex_opcode = PC_ADD;
          dst_reg = instruction[11:7];
          imm_or_reg2 = IMM;
          imm = instruction[31:12];

          r1_reg = 0;
          r2_reg = 0;
          mem_opcode = 3;
        end

        7'b1100111: begin
          // JALR
          ex_opcode = JUMP;
          mem_opcode = 3;
          branch_type = JALR;
          dst_reg = instruction[11:7];
          imm_or_reg2 = IMM;
          imm = {{52{instruction[31]}}, instruction[31:20]};
          r1_reg = instruction[19:15];
        end

        7'b1101111: begin
          // JAL
          ex_opcode = JUMP;
          mem_opcode = 3;
          branch_type = JAL;
          dst_reg = instruction[11:7];
          imm_or_reg2 = IMM;
          imm[20] = instruction[31];
          imm[10:1] = instruction[30:21];
          imm[11] = instruction[20];
          imm[19:12] = instruction[19:12];
          imm[0] = 1'b0;
          imm[63:21] = {43{imm[20]}};
        end

        7'b1100011: begin
          ex_opcode = JUMP;
          // Conditional Branches
          funct3 = instruction[14:12];

          imm[12]   = instruction[31];
          imm[10:5] = instruction[30:25];
          imm[4:1]  = instruction[11:8];
          imm[11]   = instruction[7];
          imm[0]    = 1'b0;

          imm[63:13] = {52{instruction[31]}};
          imm_or_reg2 = REG2;

          dst_reg = 0;
          r1_reg = instruction[19:15];
          r2_reg = instruction[24:20];
          mem_opcode = 3;

          case(funct3)
            3'b000: begin
              branch_type = BEQ;
            end
            3'b001: begin
              branch_type = BNE;
            end
            3'b100: begin
              branch_type = BLT;
            end
            3'b101: begin
              branch_type = BGE;
            end
            3'b110: begin
              branch_type = BLTU;
            end
            3'b111: begin
              branch_type = BGEU;
            end
          endcase
        end

        7'b0000011: begin
          // LOAD
          ex_opcode = ADD;
          mem_opcode = 1;
          funct3 = instruction[14:12];
          
          r1_reg = instruction[19:15];
          imm = {{52{instruction[31]}}, instruction[31:20]};
          imm_or_reg2 = IMM;
          is_word_op = 0;
          dst_reg = instruction[11:7];

          case(funct3)
            3'b000: begin
              mem_operation_size = BYTE;
            end
            3'b001: begin
              mem_operation_size = HALF_WORD;
            end
            3'b010: begin
              mem_operation_size = WORD;
            end
            3'b100: begin
              mem_operation_size = UNSIGNED_BYTE;
            end
            3'b101: begin
              mem_operation_size = UNSIGNED_HALF_WORD;
            end
            3'b110: begin
              mem_operation_size = UNSIGNED_WORD;
            end
            3'b011: begin
              mem_operation_size = DOUBLE_WORD;
            end
          endcase
        end

        7'b0100011: begin
          ex_opcode = ADD;
          mem_opcode = 2;
          funct3 = instruction[14:12];

          r1_reg = instruction[19:15];
          r2_reg = instruction[24:20];
          imm = {instruction[31:25], instruction[11:7]};
          imm[63:12] = {52{instruction[31]}};
          imm_or_reg2 = IMM;
          is_word_op = 0;

          case(funct3)
            3'b000: begin
              mem_operation_size = BYTE;
            end
            3'b001: begin
              mem_operation_size = HALF_WORD;
            end
            3'b010: begin
              mem_operation_size = WORD;
            end
            3'b011: begin
              mem_operation_size = DOUBLE_WORD;
            end
          endcase
        end

        7'b1110011: begin
          // ECALL
          ecall = 1;
          dst_reg = 0;
          ex_opcode = NOP;
          mem_opcode = 0;
          r1_reg = 0;
          r2_reg = 0;
        end

        default: begin
          dst_reg = 0;
          ex_opcode = NOP;
          mem_opcode = 0;
          r1_reg = 0;
          r2_reg = 0;
          $display("UNKNOWN INSTRUCTION at PC: %h", instruction_pc);
        end
      endcase
    end
  end

endmodule
