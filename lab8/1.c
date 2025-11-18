#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100


char S[MAX];
int TOP = -1;


void push(char c) {
    S[++TOP] = c;
}

char pop() {
    return S[TOP--];
}


int F(char x) {
    switch (x) {
        case '+': case '-': return 1;
        case '*': case '/': return 3;
        case '^': return 6;
        case '(': return 9;
        case ')': return 0;
        default: return 7;  
    }
}


int G(char x) {
    switch (x) {
        case '+': case '-': return 2;
        case '*': case '/': return 4;
        case '^': return 5;
        case '(': return 0;
        default: return 8;  
    }
}


int R(char x) {
    switch (x) {
        case '+': case '-':
        case '*': case '/':
        case '^': return -1;
        default: return 1;  
    }
}

void reverse(char *str) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(str) - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void main() {
    char infix[MAX], postfix[MAX] = "", prefix[MAX];
    int i = 0, rank = 0;
    char next, temp;

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    reverse(infix);

    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    strcat(infix, ")");

    TOP = -1;
    push('(');
    postfix[0] = '\0';

    i = 0;
    next = infix[i++];

    while (next != '\0') {

        while (G(S[TOP]) > F(next)) {
            temp = pop();
            strncat(postfix, &temp, 1);
            rank += R(temp);
            if (rank < 1) {
                printf("INVALID\n");
                return 0;
            }
        }

        if (G(S[TOP]) != F(next)) {
            push(next);
        } else {
            pop();
        }

        next = infix[i++];
    }

    if (rank != 1 || TOP != -1) {
        printf("INVALID EXPRESSION\n");
        return;
    }


    strcpy(prefix, postfix);
    reverse(prefix);

    printf("Prefix Expression: %s\n", prefix);
    printf("VALID\n");
}
