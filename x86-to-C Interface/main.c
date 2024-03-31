#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

extern void stencil_x86(float* X, float* Y, int n);

void stencil(float X[], float Y[], int n) {
    for (int i = 3; i < n - 3; i++) {
        Y[i] = X[i - 3] + X[i - 2] + X[i - 1] + X[i] + X[i + 1] + X[i + 2] + X[i + 3];
    }
}

int main() {
	return 0;
}