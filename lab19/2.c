//  Write a program to implement queue using linked list. 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;

struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL) {
        printf("Queue underflow\n");
        return -1; 
    }
    struct Node* temp = front;
    int dequeuedValue = front->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return dequeuedValue;
}

void display() {
    struct Node* temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
    printf("Dequeued element: %d\n", dequeue());
}