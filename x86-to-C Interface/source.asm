section .text
bits 64
default rel 

global stencil_x86

stencil_x86:
    ; Parameters
    ; rcx: address of input vector X
    ; rdx: index of the cell (i)
    
    MOV r9, rdx         ; copy the index to r9
    MOV rdi, rcx        ; base address of X
    IMUL r9, r9, 4      ; multiply index by 4 (size of float)
    ADD r9, rdi         ; address of X[i] = rdi + r9

    ; Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]
    MOVSS xmm0, [r9 - 12]  ; xmm0 = X[i - 3]
    MOVSS xmm1, [r9 - 8]   ; xmm1 = X[i - 2]
    MOVSS xmm2, [r9 - 4]   ; xmm2 = X[i - 1]
    MOVSS xmm3, [r9]       ; xmm3 = X[i]
    MOVSS xmm4, [r9 + 4]   ; xmm4 = X[i + 1]
    MOVSS xmm5, [r9 + 8]   ; xmm5 = X[i + 2]
    MOVSS xmm6, [r9 + 12]  ; xmm6 = X[i + 3]

    ADDSS xmm0, xmm1 ; xmm0 = X[i - 3] + X[i - 2]
    ADDSS xmm0, xmm2 ; xmm0 += X[i - 1]
    ADDSS xmm0, xmm3 ; xmm0 += X[i]
    ADDSS xmm0, xmm4 ; xmm0 += X[i + 1]
    ADDSS xmm0, xmm5 ; xmm0 += X[i + 2]
    ADDSS xmm0, xmm6 ; xmm0 += X[i + 3]

    ret