.section .text
.globl _start

_start:
    addi x1, x0, -1
    srai x1, x1, 33
    ret
