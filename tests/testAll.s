.section .text
.globl _start

_start:
    addi a0, x0, -1021
    slli a0, a0, 31
    addi a1, x0, 256
    div  a2, a0, a1
    ret
