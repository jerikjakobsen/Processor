.section .data
value:    .dword 42        # Declare a doubleword in memory and initialize it to 42

.section .text
.globl _start
_start:
    # Step 1: Load the address of 'value' into a register (create a pointer)
    la t0, value           # Load the address of 'value' into t0

    # Step 2: Store a new doubleword value at the address pointed to by t0
    li t1, 99              # Load immediate value 99 into t1
#    sd t1, 0(t0)           # Store the value in t1 at the memory address in t0

    # Step 3: Load the doubleword value back from the memory address into another register
    ld t2, 0(t0)           # Load the value from the address in t0 into t2

    # Exit (for simulation purposes, use an infinite loop)
    j _start               # Infinite loop to halt the program