#include <stdio.h>

void main() {
    int n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    int *p = arr;

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++){
        scanf("%d", p + i);
    }

    int max = *p;

    for (i = 1; i < n; i++){
        if (*(p + i) > max){
            max = *(p + i);
        }
    }

    printf("Largest element = %d\n", max);

}
