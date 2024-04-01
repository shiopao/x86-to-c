section .text
bits 64
default rel 

;global stencil_x86

stencil_x86:
    ; Parameters
    ; rdi: vector X
    ; rsi: vector Y
    ; rdx: number of elements in X and Y

    MOV ecx, 3 ; loop counter (i = 3)

stencil_loop:
    MOV rax, rdi    ; base address of X
    MOV r8, rsi     ; base address of Y
    MOV r9, rdx     ; number of elements in X and Y
    IMUL r9, rcx, 4 ; adjust loop to size of float
    ADD rax, r9     ; address of X[i]
    ADD r8, r9      ; address of Y[i]

    ; Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3]
    MOVSS xmm0, [rax - 12]  ; xmm0 = X[i - 3]
    MOVSS xmm1, [rax - 8]   ; xmm1 = X[i - 2]
    MOVSS xmm2, [rax - 4]   ; xmm2 = X[i - 1]
    MOVSS xmm3, [rax]       ; xmm3 = X[i]
    MOVSS xmm4, [rax + 4]   ; xmm4 = X[i + 1]
    MOVSS xmm5, [rax + 8]   ; xmm5 = X[i + 2]
    MOVSS xmm6, [rax + 12]  ; xmm6 = X[i + 3]
    
    ADDSS xmm0, xmm1 ; xmm0 = X[i - 3] + X[i - 2]
    ADDSS xmm0, xmm2 ; xmm0 += X[i - 1]
    ADDSS xmm0, xmm3 ; xmm0 += X[i]
    ADDSS xmm0, xmm4 ; xmm0 += X[i + 1]
    ADDSS xmm0, xmm5 ; xmm0 += X[i + 2]
    ADDSS xmm0, xmm6 ; xmm0 += X[i + 3]

    MOVSS [r8], xmm0 ; store result in Y[i]

    INC ecx ; increment loop counter
    
    CMP ecx, edx 
    JL stencil_loop ; continue if i < n - 3

	ret