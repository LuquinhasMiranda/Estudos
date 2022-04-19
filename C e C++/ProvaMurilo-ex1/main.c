// Murilo Afareli Marchette Costa 12111EQU004

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main () {
    int n;
    scanf(" %d", &n);

    int *A = malloc(n*sizeof(int));
    int *B = malloc(n*sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf(" %d", &A[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf(" %d", &B[i]);
    }
    printf("\n\n");

    for (int i = 0; i < n; i++) {
        printf("%d  %d \n", *(A+i), *(B+i));
    }
    printf("\n");
    printf("%d", Chebyshev(A, B, n));
}

int Chebyshev (int *A, int *B, int n) {
    int dFinal = -1;
    for (int i = 0; i < n; i++) {
        int dist = fabs(*(A+i)-*(B+i));
        if (dFinal < dist)
            dFinal = dist;
    }
    return dFinal;
}
