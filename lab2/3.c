#include <stdio.h>

void main() {
    int n, i, a, b;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    printf("Enter number to replace: ");
    scanf("%d", &a);

    printf("Enter new number: ");
    scanf("%d", &b);

    for (i = 0; i < n; i++){
        if (arr[i] == a){
            arr[i] = b;
        }
    }

    printf("Array after replacement:\n");
    for (i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

}
