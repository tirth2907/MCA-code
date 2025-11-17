#include <stdio.h>

void main() {
    int n, i, j = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], temp[n];

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n - 1; i++){
        if (arr[i] != arr[i + 1]){
            temp[j++] = arr[i];
        }
    }

    temp[j++] = arr[n - 1];

    printf("after removing duplicates:\n");
    for (i = 0; i < j; i++){
        printf("%d ", temp[i]);
    }

}
