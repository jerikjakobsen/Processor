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
    output wire mem_opcode,
    output wire is_mem_load
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
            LOAD_MEM = 4'd12,
            STORE_MEM = 4'd13;
  
  parameter BEQ  = 3'b000,
            BNE  = 3'b001,
            BLT  = 3'b010,
            BGE  = 3'b011,
            BLTU = 3'b100,
            BGEU = 3'b101,
            JAL = 3'b110,
            JALR = 3'b111;

  logic [6:0] opcode;
  logic [2:0] funct3;
  logic [6:0] funct7;

  always_comb begin
    ready = (instruction == 0 || next_stage_ready);
    next_stage_pc = instruction_pc;
  end

  always_comb begin
    if(instruction == 0) begin
      // NOP
      ex_opcode = 0;
    end else begin
      opcode = instruction[6:0];
      case (opcode)
        7'b0010011: begin
            funct3 = instruction[14:12];

            case (funct3)
                // ADDI
                3'b000: begin
                  r1_reg = instruction[19:15];
                  imm = {{52{instruction[31]}}, instruction[31:20]};
                  imm_or_reg2 = IMM;
                  ex_opcode = ADD;
                  is_word_op = 0;
                  dst_reg = instruction[11:7];
                end

                // ANDI
                3'b111: begin
                  ex_opcode = AND;
                  is_word_op = 0;
                  dst_reg = instruction[11:7];
                  r1_reg = instruction[19:15];
                  imm_or_reg2 = IMM;
                  imm = {{52{instruction[31]}}, instruction[31:20]};
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

          case(funct3)
            // ADDIW
            3'b000: begin
              r1_reg = instruction[19:15];
              imm = {{52{instruction[31]}}, instruction[31:20]};
              imm_or_reg2 = IMM;
              ex_opcode = ADD;
              is_word_op = 1;
              dst_reg = instruction[11:7];
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

        7'b1100111: begin
          funct3 = instruction[14:12];
          case(funct3)
            3'b000: begin
              // JALR
              ex_opcode = JUMP;
              branch_type = JALR;
              dst_reg = instruction[11:7];
              imm_or_reg2 = IMM;
              imm = {{52{instruction[31]}}, instruction[31:20]};
              r1_reg = instruction[19:15];
            end

            default: begin
              // JAL
              ex_opcode = JUMP;
              branch_type = JAL;
              dst_reg = instruction[11:7];
              imm_or_reg2 = IMM;
              imm[20] = instruction[31];
              imm[10:1] = instruction[30:21];
              imm[11] = instruction[20];
              imm[19:12] = instruction[19:12];
              imm[0] = 1'b0;
              imm[63:21] = {43{instruction[31]}};
            end
          endcase
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

          dst_reg = 0;
          r1_reg = instruction[19:15];
          r2_reg = instruction[24:20];

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
          ex_opcode = LOAD_MEM;
        end

        7'b0100011: begin
          ex_opcode = STORE_MEM;
        end

        default: begin
          dst_reg = 0;
          ex_opcode = NOP;
          r1_reg = 0;
          r2_reg = 0;
        end
      endcase
    end
  end

endmodule



// Load
// Store



  //  0:	fe010113          	addi	sp,sp,-32
  //  4:	00113c23          	sd	ra,24(sp)
  //  8:	00813823          	sd	s0,16(sp)
  //  c:	02010413          	addi	s0,sp,32
  // 10:	fea42623          	sw	a0,-20(s0)
  // 14:	feb43023          	sd	a1,-32(s0)
  // 18:	000007b7          	lui	a5,0x0
  // 1c:	00078513          	mv	a0,a5
  // 20:	00000317          	auipc	t1,0x0
  // 24:	000300e7          	jalr	t1
  // 28:	00000793          	li	a5,0
  // 2c:	00078513          	mv	a0,a5
  // 30:	01813083          	ld	ra,24(sp)
  // 34:	01013403          	ld	s0,16(sp)
  // 38:	02010113          	addi	sp,sp,32
  // 3c:	00008067          	ret


// LB
// LH
// LW
// LBU
// LHU
// LWU
// LD

// SB
// SH
// SW
// SD