#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack
char S[MAX];
int TOP = -1;

// Push
void push(char x)
{
    S[++TOP] = x;
}

// Pop
char pop()
{
    if (TOP == -1)
        return '\0';
    return S[TOP--];
}

// Input Precedence Function (F)
int F(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 3;
    case '^':
        return 6;
    case '(':
        return 9;
    case ')':
        return 0;
    default:
        return 7;
    }
}

// Stack Precedence Function (G)
int G(char x)
{
    switch (x)
    {
    case '+':
    case '-':
        return 2;
    case '*':
    case '/':
        return 4;
    case '^':
        return 5;
    case '(':
        return 0;
    default:
        return 8;
    }
}

// Rank Function
int R(char x)
{
    switch (x)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return -1;
    default:
        return 1;
    }
}

void main()
{
    char infix[MAX], postfix[MAX] = "";
    char next, temp;
    int i = 0, rank = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    push('(');

    strcat(infix, ")");

    next = infix[i++];

    while (next != '\0')
    {

        while (G(S[TOP]) > F(next))
        {
            temp = pop();
            strncat(postfix, &temp, 1);
            rank += R(temp);

            if (rank < 1)
            {
                printf("INVALID\n");
                return 0;
            }
        }

        if (G(S[TOP]) != F(next))
        {
            push(next);
        }
        else
        {
            pop();
        }

        next = infix[i++];
    }

    if (TOP != -1 || rank != 1)
    {
        printf("INVALID\n");
    }
    else
    {
        printf("Postfix Expression: %s\n", postfix);
        printf("VALID\n");
    }


}
