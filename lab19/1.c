#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1; 
    }
    struct Node* temp = top;
    int poppedValue = top->data;
    top = top->next;
    free(temp);
    return poppedValue;
}

void display() {
    struct Node* temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main(){
    push(10);
    push(20);
    push(30);
    push(40);
    display();
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
    printf("Popped element: %d\n", pop());
}