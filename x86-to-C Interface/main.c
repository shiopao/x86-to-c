#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

extern void stencil_x86(float* X, float* Y, int n);

void stencil(float X[], float Y[], int n) {
    for (int i = 3; i <= n - 3; i++) {
        Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

int main() {
    int n, size;

    printf("Enter the exponent (n) to determine the size of the vector (2^n): ");
    scanf_s("%d", &n);

    size = (int)pow(2, n);

    float* X = (float*)malloc(size * sizeof(float));
    float* Y = (float*)malloc(size * sizeof(float));

    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++) {
        X[i] = (float)rand() / RAND_MAX;
    }

    /*
    stencil(X, Y, size);

    printf("Vector Y (stencil function): ");
    for (int i = 3; i < size - 3; i++) {
        printf("%.2f ", Y[i]);
    }
    printf("\n");
    */

    clock_t start, end;
    double cpu_time_used;
    int iterations = 30;

    // Timing for C kernel
    start = clock();

    for (int i = 0; i < iterations; i++) {
        stencil(X, Y, size);
    }
    
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC / iterations;
    printf("Average execution time for C version: %f seconds\n", cpu_time_used);

    // stencil_x86(X, Y, n);
    
    free(X);
    free(Y);

	return 0;
}