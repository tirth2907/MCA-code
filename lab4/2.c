#include <stdio.h>

void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
    printf("x = %d, x = %d\n", a, b);
}

void main() {
    int x, y;

    printf("Enter two numbers: ");
    scanf("%d %d", &x, &y);

    swap(x, y);

    printf("x = %d, y = %d\n", x, y);

}

