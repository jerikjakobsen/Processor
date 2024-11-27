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
    if(instruction == 0) begin
      // NOP
      ex_opcode = 0;
    end else begin
      opcode = instruction[6:0];
      case (opcode)
        7'b0010011: begin
            funct3 = instruction[14:12];
            mem_opcode = 3;

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
          mem_opcode = 3;

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



  //  0:	fe010113          	addi	x2,x2,-32
  //  4:	00113c23          	sd	x1,24(x2)
  //  8:	00813823          	sd	x8,16(x2)
  //  c:	02010413          	addi	x8,x2,32
  // 10:	fea42623          	sw	x10,-20(x8)
  // 14:	feb43023          	sd	x11,-32(x8)
  // 18:	000007b7          	lui	x15,0x0
  // 1c:	00078513          	mv	x10,x15
  // 20:	00000317          	auipc	x6,0x0
  // 24:	000300e7          	jalr	x6
  // 28:	00000793          	li	x15,0
  // 2c:	00078513          	mv	x10,x15
  // 30:	01813083          	ld	x1,24(x2)
  // 34:	01013403          	ld	x8,16(x2)
  // 38:	02010113          	addi	x2,x2,32
  // 3c:	00008067          	ret

//  0:	fd010113          	addi	x2,x2,-48
//    4:	02113423          	sd	x1,40(x2)
//    8:	02813023          	sd	x8,32(x2)
//    c:	03010413          	addi	x8,x2,48
//   10:	fea43423          	sd	x10,-24(x8)
//   14:	feb42223          	sw	x11,-28(x8)
//   18:	fcc43c23          	sd	x12,-40(x8)
//   1c:	fd843783          	ld	x15,-40(x8)
//   20:	00c7a783          	lw	x15,12(x15)
//   24:	fff7871b          	addiw	x14,x15,-1
//   28:	fd843783          	ld	x15,-40(x8)
//   2c:	00e7a623          	sw	x14,12(x15)
//   30:	fd843783          	ld	x15,-40(x8)
//   34:	00c7a783          	lw	x15,12(x15)
//   38:	0207d463          	bgez	x15,0x60
//   3c:	fd843783          	ld	x15,-40(x8)
//   40:	00c7a703          	lw	x14,12(x15)
//   44:	fd843783          	ld	x15,-40(x8)
//   48:	0287a783          	lw	x15,40(x15)
//   4c:	02f74e63          	blt	x14,x15,0x88
//   50:	fe442783          	lw	x15,-28(x8)
//   54:	0ff7f713          	andi	x14,x15,255
//   58:	00a00793          	li	x15,10
//   5c:	02f70663          	beq	x14,x15,0x88
//   60:	fd843783          	ld	x15,-40(x8)
//   64:	0007b783          	ld	x15,0(x15)
//   68:	00178693          	addi	x13,x15,1
//   6c:	fd843703          	ld	x14,-40(x8)
//   70:	00d73023          	sd	x13,0(x14)
//   74:	fe442703          	lw	x14,-28(x8)
//   78:	0ff77713          	andi	x14,x14,255
//   7c:	00e78023          	sb	x14,0(x15)
//   80:	0007c783          	lbu	x15,0(x15)
//   84:	01c0006f          	j	0xa0
//   88:	fd843603          	ld	x12,-40(x8)
//   8c:	fe442583          	lw	x11,-28(x8)
//   90:	fe843503          	ld	x10,-24(x8)
//   94:	00000317          	auipc	x6,0x0
//   98:	000300e7          	jalr	x6
//   9c:	00050793          	mv	x15,x10
//   a0:	00078513          	mv	x10,x15
//   a4:	02813083          	ld	x1,40(x2)
//   a8:	02013403          	ld	x8,32(x2)
//   ac:	03010113          	addi	x2,x2,48
//   b0:	00008067          	ret
//   b4:	fd010113          	addi	x2,x2,-48
//   b8:	02113423          	sd	x1,40(x2)
//   bc:	02813023          	sd	x8,32(x2)
//   c0:	00913c23          	sd	x9,24(x2)
//   c4:	03010413          	addi	x8,x2,48
//   c8:	fca42e23          	sw	x10,-36(x8)
//   cc:	fcb42c23          	sw	x11,-40(x8)
//   d0:	fcc43823          	sd	x12,-48(x8)
//   d4:	fdc42703          	lw	x14,-36(x8)
//   d8:	00100793          	li	x15,1
//   dc:	10e7d663          	ble	x14,x15,0x1e8
//   e0:	fdc42703          	lw	x14,-36(x8)
//   e4:	00200793          	li	x15,2
//   e8:	06e7c263          	blt	x15,x14,0x14c
//   ec:	00100713          	li	x14,1
//   f0:	fd842783          	lw	x15,-40(x8)
//   f4:	40f704bb          	subw	x9,x14,x15
//   f8:	fd043783          	ld	x15,-48(x8)
//   fc:	00178793          	addi	x15,x15,1
//  100:	00078613          	mv	x12,x15
//  104:	00000593          	li	x11,0
//  108:	faa00513          	li	x10,-86
//  10c:	00000317          	auipc	x6,0x0
//  110:	000300e7          	jalr	x6
//  114:	00050793          	mv	x15,x10
//  118:	fd043703          	ld	x14,-48(x8)
//  11c:	00f707b3          	add	x15,x14,x15
//  120:	00078613          	mv	x12,x15
//  124:	00048593          	mv	x11,x9
//  128:	fa900513          	li	x10,-87
//  12c:	00000317          	auipc	x6,0x0
//  130:	000300e7          	jalr	x6
//  134:	00050793          	mv	x15,x10
//  138:	00078613          	mv	x12,x15
//  13c:	ff300593          	li	x11,-13
//  140:	fb100513          	li	x10,-79
//  144:	00000317          	auipc	x6,0x0
//  148:	000300e7          	jalr	x6
//  14c:	fdc42703          	lw	x14,-36(x8)
//  150:	fd842783          	lw	x15,-40(x8)
//  154:	02f75063          	ble	x15,x14,0x174
//  158:	fdc42783          	lw	x15,-36(x8)
//  15c:	0017879b          	addiw	x15,x15,1
//  160:	fd043603          	ld	x12,-48(x8)
//  164:	fd842583          	lw	x11,-40(x8)
//  168:	00078513          	mv	x10,x15
//  16c:	00000317          	auipc	x6,0x0
//  170:	000300e7          	jalr	x6
//  174:	fdc42783          	lw	x15,-36(x8)
//  178:	fe57879b          	addiw	x15,x15,-27
//  17c:	fd043603          	ld	x12,-48(x8)
//  180:	00078593          	mv	x11,x15
//  184:	fa200513          	li	x10,-94
//  188:	00000317          	auipc	x6,0x0
//  18c:	000300e7          	jalr	x6
//  190:	00050793          	mv	x15,x10
//  194:	04078663          	beqz	x15,0x1e0
//  198:	fdc42703          	lw	x14,-36(x8)
//  19c:	00200793          	li	x15,2
//  1a0:	04f71063          	bne	x14,x15,0x1e0
//  1a4:	fd842703          	lw	x14,-40(x8)
//  1a8:	00c00793          	li	x15,12
//  1ac:	02e7c663          	blt	x15,x14,0x1d8
//  1b0:	fd842783          	lw	x15,-40(x8)
//  1b4:	0017871b          	addiw	x14,x15,1
//  1b8:	000007b7          	lui	x15,0x0
//  1bc:	00078613          	mv	x12,x15
//  1c0:	00070593          	mv	x11,x14
//  1c4:	00200513          	li	x10,2
//  1c8:	00000317          	auipc	x6,0x0
//  1cc:	000300e7          	jalr	x6
//  1d0:	00050793          	mv	x15,x10
//  1d4:	1a40006f          	j	0x378
//  1d8:	00900793          	li	x15,9
//  1dc:	19c0006f          	j	0x378
//  1e0:	01000793          	li	x15,16
//  1e4:	1940006f          	j	0x378
//  1e8:	fdc42783          	lw	x15,-36(x8)
//  1ec:	0e07dc63          	bgez	x15,0x2e4
//  1f0:	fdc42703          	lw	x14,-36(x8)
//  1f4:	fb800793          	li	x15,-72
//  1f8:	02f75263          	ble	x15,x14,0x21c
//  1fc:	000007b7          	lui	x15,0x0
//  200:	00078613          	mv	x12,x15
//  204:	fdc42583          	lw	x11,-36(x8)
//  208:	fd842503          	lw	x10,-40(x8)
//  20c:	00000317          	auipc	x6,0x0
//  210:	000300e7          	jalr	x6
//  214:	00050793          	mv	x15,x10
//  218:	1600006f          	j	0x378
//  21c:	fdc42703          	lw	x14,-36(x8)
//  220:	fce00793          	li	x15,-50
//  224:	06f75e63          	ble	x15,x14,0x2a0
//  228:	fd043783          	ld	x15,-48(x8)
//  22c:	0007c783          	lbu	x15,0(x15) # 0x0
//  230:	00078713          	mv	x14,x15
//  234:	fd842783          	lw	x15,-40(x8)
//  238:	04e79263          	bne	x15,x14,0x27c
//  23c:	000007b7          	lui	x15,0x0
//  240:	0007b703          	ld	x14,0(x15) # 0x0
//  244:	fd043783          	ld	x15,-48(x8)
//  248:	01f78793          	addi	x15,x15,31
//  24c:	0007c783          	lbu	x15,0(x15)
//  250:	00078693          	mv	x13,x15
//  254:	000007b7          	lui	x15,0x0
//  258:	0007b783          	ld	x15,0(x15) # 0x0
//  25c:	0107b783          	ld	x15,16(x15)
//  260:	00078613          	mv	x12,x15
//  264:	00068593          	mv	x11,x13
//  268:	00070513          	mv	x10,x14
//  26c:	00000317          	auipc	x6,0x0
//  270:	000300e7          	jalr	x6
//  274:	00050793          	mv	x15,x10
//  278:	1000006f          	j	0x378
//  27c:	fd043783          	ld	x15,-48(x8)
//  280:	00178793          	addi	x15,x15,1
//  284:	00078613          	mv	x12,x15
//  288:	fd842583          	lw	x11,-40(x8)
//  28c:	fbf00513          	li	x10,-65
//  290:	00000317          	auipc	x6,0x0
//  294:	000300e7          	jalr	x6
//  298:	00050793          	mv	x15,x10
//  29c:	0dc0006f          	j	0x378
//  2a0:	fd043783          	ld	x15,-48(x8)
//  2a4:	0007c783          	lbu	x15,0(x15)
//  2a8:	fd17879b          	addiw	x15,x15,-47
//  2ac:	0017b793          	seqz	x15,x15
//  2b0:	0ff7f793          	andi	x15,x15,255
//  2b4:	00078713          	mv	x14,x15
//  2b8:	fdc42783          	lw	x15,-36(x8)
//  2bc:	00f7073b          	addw	x14,x14,x15
//  2c0:	fd043783          	ld	x15,-48(x8)
//  2c4:	00178793          	addi	x15,x15,1
//  2c8:	00078613          	mv	x12,x15
//  2cc:	fd842583          	lw	x11,-40(x8)
//  2d0:	00070513          	mv	x10,x14
//  2d4:	00000317          	auipc	x6,0x0
//  2d8:	000300e7          	jalr	x6
//  2dc:	00050793          	mv	x15,x10
//  2e0:	0980006f          	j	0x378
//  2e4:	fdc42783          	lw	x15,-36(x8)
//  2e8:	02f05263          	blez	x15,0x30c
//  2ec:	000007b7          	lui	x15,0x0
//  2f0:	00078613          	mv	x12,x15
//  2f4:	00200593          	li	x11,2
//  2f8:	00200513          	li	x10,2
//  2fc:	00000317          	auipc	x6,0x0
//  300:	000300e7          	jalr	x6
//  304:	00050793          	mv	x15,x10
//  308:	0700006f          	j	0x378
//  30c:	fd043783          	ld	x15,-48(x8)
//  310:	0007c703          	lbu	x14,0(x15) # 0x0
//  314:	02f00793          	li	x15,47
//  318:	04f70863          	beq	x14,x15,0x368
//  31c:	fd043783          	ld	x15,-48(x8)
//  320:	0007c783          	lbu	x15,0(x15)
//  324:	00078713          	mv	x14,x15
//  328:	000007b7          	lui	x15,0x0
//  32c:	00078613          	mv	x12,x15
//  330:	00070593          	mv	x11,x14
//  334:	fc300513          	li	x10,-61
//  338:	00000317          	auipc	x6,0x0
//  33c:	000300e7          	jalr	x6
//  340:	00050713          	mv	x14,x10
//  344:	fd043783          	ld	x15,-48(x8)
//  348:	00178793          	addi	x15,x15,1 # 0x1
//  34c:	00078613          	mv	x12,x15
//  350:	00070593          	mv	x11,x14
//  354:	00000513          	li	x10,0
//  358:	00000317          	auipc	x6,0x0
//  35c:	000300e7          	jalr	x6
//  360:	00050793          	mv	x15,x10
//  364:	00078663          	beqz	x15,0x370
//  368:	00100793          	li	x15,1
//  36c:	00c0006f          	j	0x378
//  370:	00000793          	li	x15,0
//  374:	0040006f          	j	0x378
//  378:	00000013          	nop
//  37c:	00078513          	mv	x10,x15
//  380:	02813083          	ld	x1,40(x2)
//  384:	02013403          	ld	x8,32(x2)
//  388:	01813483          	ld	x9,24(x2)
//  38c:	03010113          	addi	x2,x2,48
//  390:	00008067          	ret