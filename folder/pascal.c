#include <stdio.h>

int main() {
    int rows, i, j, space, num = 1;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    for (i = 0; i < rows; i++) {
        // 1. Logic for Spaces: Shifts the triangle to the center
        for (space = 1; space <= rows - i; space++) {
            printf(" ");
        }

        for (j = 0; j <= i; j++) {
            // 2. Logic for Numbers:
            // First element of every row is always 1
            if (j == 0) {
                num = 1;
            } else {
                // Mathematical trick to get the next number in the row
                num = num * (i - j + 1) / j;
            }
            printf("%d ", num);
        }
        printf("\n"); // Move to t
    }
    return 0;
}