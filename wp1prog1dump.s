
/home/kuchadha/cse_502_cpu/tests/test1.o:     file format elf64-littleriscv


Disassembly of section .text:

0000000000000000 <_start>:
   0:	000982b7          	lui	x5,0x98
   4:	6002829b          	addiw	x5,x5,1536
   8:	00449337          	lui	x6,0x449
   c:	8cd3031b          	addiw	x6,x6,-1843
  10:	00e31313          	slli	x6,x6,0xe
  14:	45530313          	addi	x6,x6,1109 # 449455 <_start+0x449455>
  18:	00c31313          	slli	x6,x6,0xc
  1c:	66730313          	addi	x6,x6,1639
  20:	00c31313          	slli	x6,x6,0xc
  24:	78830313          	addi	x6,x6,1928
  28:	0062b023          	sd	x6,0(x5) # 98000 <_start+0x98000>
  2c:	000263b7          	lui	x7,0x26
  30:	6ab3839b          	addiw	x7,x7,1707
  34:	00e39393          	slli	x7,x7,0xe
  38:	bcc38393          	addi	x7,x7,-1076 # 25bcc <_start+0x25bcc>
  3c:	0072a423          	sw	x7,8(x5)
  40:	0000e437          	lui	x8,0xe
  44:	dee4041b          	addiw	x8,x8,-530
  48:	00829623          	sh	x8,12(x5)
  4c:	0ff00493          	li	x9,255
  50:	00928723          	sb	x9,14(x5)
  54:	05d00893          	li	x17,93
  58:	00000073          	ecall

Disassembly of section .rodata:

0000000000000000 <rodata_example>:
   0:	6548                	ld	x10,136(x10)
   2:	6c6c                	ld	x11,216(x8)
   4:	77202c6f          	jal	x24,2776 <rodata_example+0x2776>
   8:	646c726f          	jal	x4,c764e <rodata_example+0xc764e>
   c:	0021                	0x21

Disassembly of section .comment:

0000000000000000 <.comment>:
   0:	656e6547          	0x656e6547
   4:	6172                	ld	x2,280(x2)
   6:	6574                	ld	x13,200(x10)
   8:	2064                	fld	f9,192(x8)
   a:	7962                	ld	x18,56(x2)
   c:	7220                	ld	x8,96(x12)
   e:	7369                	lui	x6,0xffffa
  10:	34367663          	bleu	x3,x12,35c <_start+0x35c>
  14:	752d                	lui	x10,0xfffeb
  16:	6b6e                	ld	x22,216(x2)
  18:	6f6e                	ld	x30,216(x2)
  1a:	652d6e77          	0x652d6e77
  1e:	666c                	ld	x11,200(x12)
  20:	672d                	lui	x14,0xb
  22:	00006363          	bltu	x0,x0,28 <_start+0x28>
