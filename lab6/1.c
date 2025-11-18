#include "stdio.h"

#define n 10

int s[n];
int top = -1;

void push(int val, int s[]) {
    if (top == n - 1) {
        printf("Stack Overflow\n");
    }
    else {
        top++;
        s[top] = val;
    }
}

int pop (int s[]){
    if(top == -1){
        printf("stack underflow\n");
    }
    else{
        top--;
        return(s[top + 1]);
    }
}

int peep (int s[],int i){
    if(top-i+1<0){
        printf("invalid position\n");
    }
    else{
        return(s[top - i + 1]);
    }
}

void change(int s[], int i, int val){
    if(top-i+1<0){
        printf("invalid position\n");
    }
    else{
        s[top - i + 1] = val;
    }
}

void display(int s[]){
    if(top == -1){
        printf("stack is empty\n");
    }
    else{
        for(int i=top;i>=0;i--){
            printf("%d\n",s[i]);
        }
    }
}


void main()
{
    push(10,s);
    push(20,s);
    push(30,s);
    push(40,s);
    display(s);
    printf("popped element is %d\n",pop(s));
    display(s);
    printf("element at position 2 is %d\n",peep(s,2));
    change(s,2,100);
    display(s);
}