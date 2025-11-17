#include "stdio.h"

void main()
{
    int n,ans=0;
    float avg=0;
    printf("Enter a length of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        ans += arr[i];
    }
    avg = (float)ans / n;
    printf("Sum = %d\n", ans);
    printf("Average = %f\n", avg);
}