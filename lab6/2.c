#include <stdio.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
    } else {
        stack[++top] = c;
    }
}
char pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return '\0';
    } else {
        return stack[top--];
    }
}
void reverseString(char str[]) {
    int n = strlen(str);
    for (int i = 0; i < n; i++) {
        push(str[i]);
    }
    for (int i = 0; i < n; i++) {
        str[i] = pop();
    }
}

void main() {
    char str[MAX];
    printf("Enter a string: ");
    gets(str);
    // str[top] = '\0';
    reverseString(str);
    printf("Reversed string is: ");
    puts(str);
}