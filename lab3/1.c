#include <stdio.h>

void main() {
    int A[2][2], B[2][2], C[2][2];
    int i, j;

    printf("Enter elements of 1st matrix:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of 2nd matrix:\n");
    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", &B[i][j]);
        }
    }

    for (i = 0; i < 2; i++){
        for (j = 0; j < 2; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Resultant Matrix \n");
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++){
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
}
