# ----------------------------------------------------------------------------------------
# 64-bit Assembly.
# NOTE: relocation R_X86_64_XX against undefined symbol means:
# 1- wrongly assigning variable to register of different sizes
# 2- it is not any thing related to PIC or PIE since being enabled on most OSs by default
# ----------------------------------------------------------------------------------------

.globl reyadeyat_assembly_allaho_akbar

#.type reyadeyat_assembly_allaho_akbar, @function
reyadeyat_assembly_allaho_akbar:
    mov     %rdi, %rax              # result (rax) initially holds x
    cmp     %rsi, %rax              # is x less than y?
    cmovl   %rsi, %rax              # if so, set result to y
    cmp     %rdx, %rax              # is max(x,y) less than z?
    cmovl   %rdx, %rax              # if so, set result to z
    ret                             # the max will be in eax

message: .asciz "Allaho akbar :)\n"
length: .long . - message
