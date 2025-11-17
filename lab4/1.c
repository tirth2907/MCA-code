#include <stdio.h>

void main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int *p = arr;

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", p + i);
    }

    printf("Array elements using pointer:\n");
    for (i = 0; i < n; i++){
        printf("%d ", *(p + i));
    }

}
