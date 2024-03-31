#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void stencil_x86(float* X, float* Y, int n);

void stencil(float X[], float Y[], int n) {
    for (int i = 3; i <= n - 3; i++) {
        Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

int main() {
    int n;

    printf("Enter the size of vector (n): ");
    scanf_s("%d", &n);

    float* X = (float*)malloc((n + 1) * sizeof(float));
    float* Y = (float*)malloc((n + 1) * sizeof(float));

    for (int i = 0; i <= n; i++) {
        X[i] = i + 1;
    }

    // Vector initialization testing
    /*
    for (int i = 0; i <= n; i++) {
        printf("%.2f ", X[i]);
    }
    */

    stencil(X, Y, n);

    printf("Vector Y (stencil function): ");
    for (int i = 3; i <= n - 3; i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");

    // stencil_x86(X, Y, n);

    /*
    printf("Vector Y (stencil_x86 function): ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n"); 
    */
    
    free(X);
    free(Y);

	return 0;
}