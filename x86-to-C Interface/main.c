#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <math.h>
#include <time.h>

extern float stencil_x86(float* X, int i);

void stencil(float X[], float Y[], int n) {
    for (int i = 3; i <= n - 3; i++) {
        Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

int main() {
    int n, size;
    int differences = 0;

    printf("Enter the exponent (n) to determine the size of the vector (2^n): ");
    scanf_s("%d", &n);
    printf("\n");

    size = (int)pow(2, n);

    float* X = (float*)malloc(size * sizeof(float));
    float* Y = (float*)malloc(size * sizeof(float));
    float* Y_x86 = (float*)malloc(size * sizeof(float));

    // Input vector X initialization
    srand((unsigned int)time(NULL));

    for (int i = 0; i < size; i++) {
        X[i] = (float)rand() / RAND_MAX;
        Y[i] = 0.0f;
        Y_x86[i] = 0.0f;
    }

    clock_t start, end;
    double time_c = 0;
    double time_x86 = 0;
    int iterations = 30;

    for (int i = 0; i < iterations; i++) {
        printf("ITERATION %d \n", i + 1);

        // C kernel timing
        start = clock();
        stencil(X, Y, size);
        end = clock();
        time_c += ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print first 10 elements of C output
        printf("First 10 elements of C version: \n");
        for (int l = 3; l < 10 + 3; l++) {
            printf("%.2f ", Y[l]);
        }
        printf("\n");

        printf("Execution time for C version: %f seconds \n", ((double)(end - start)) / CLOCKS_PER_SEC);

        // x86 kernel timing
        start = clock();
        for (int j = 3; j <= size - 3; j++) {
            Y_x86[j] = stencil_x86(X, j);
        }
        end = clock();
        time_x86 += ((double)(end - start)) / CLOCKS_PER_SEC;

        // Print first 10 elements of x86 output
        printf("First 10 elements of x86-64 version: \n");
        for (int m = 3; m < 10 + 3; m++) {
            printf("%.2f ", Y_x86[m]);
        }
        printf("\n");

        printf("Execution time for x86-64 version: %f seconds \n", ((double)(end - start)) / CLOCKS_PER_SEC);

        // Output vector Y comparison
        printf("Comparison of Y values between C and x86-64 versions: \n");
        for (int k = 3; k <= size - 3; k++) {
            if (fabs(Y[k] - Y_x86[k]) > 1e-6) {
                // printf("Difference found (Y[%d] (C) = %.6f, Y[%d] (x86-64) = %.6f). \n", i, Y[i], i, Y_x86[i]);
                differences++;
            }
        }

        if (differences) {
            printf("x86-64 version is correct. \n");
        }
        else {
            printf("x86-64 version is incorrect. \n");
        }

        printf("\n");
    }

    // Average execution time
    printf("SUMMARY \n");
    time_c /= iterations;
    printf("Average execution time for C version: %f seconds \n", time_c);
    time_x86 /= iterations;
    printf("Average execution time for x86-64 version: %f seconds \n", time_x86);
    
    free(X);
    free(Y);

	return 0;
}