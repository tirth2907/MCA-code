#include <stdio.h>

void main() {
    int n, i, j;

    printf("Enter size of square matrix (n): ");
    scanf("%d", &n);

    int A[n][n], T[n][n];

    printf("Enter elements of %dx%d matrix:\n", n, n);
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            scanf("%d", &A[i][j]);
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
           T[j][i] = A[i][j];
        }
    }

    printf("Transpose of matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++){
            printf("%d ", T[i][j]);
        }
        printf("\n");
    }

}
