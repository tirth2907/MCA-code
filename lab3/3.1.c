// find tranpose of a matrix using same matrix
#include <stdio.h>
#define MAX 10
void main() {
    int matrix[MAX][MAX], n, i, j, temp;
    printf("Enter the order of the square matrix: ");
    scanf("%d", &n);
    printf("Enter the elements of the matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    // Transpose the matrix in place
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    printf("Transposed matrix is:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}