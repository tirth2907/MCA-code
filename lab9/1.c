#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

void main() {
    char prefix[MAX];
    int i, a, b, value;

    printf("Enter Prefix Expression: ");
    scanf("%s", prefix);

    int len = strlen(prefix);


    for (i = len - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (isdigit(ch)) {  
            push(ch - '0');  
        }
        else {  
            a = pop();  
            b = pop();  

            switch (ch) {
                case '+': value = a + b; break;
                case '-': value = a - b; break;
                case '*': value = a * b; break;
                case '/': value = a / b; break;
                case '^': value = pow(a, b); break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
            push(value);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
