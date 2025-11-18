// 1. Write a menu driven program to perform following operations on Circular  
// Queue: ENQUEUE, DEQUEUE and DISPLAY.  
#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int queue[MAX];
int front = -1,rear = -1;
void enqueue(int x){
    if(rear == front -1 || (front == 0 && rear == MAX -1)){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = x;
    printf("%d enqueued to queue\n", x);    
}
int dequeue(){
    if(front == -1){
        printf("Queue Underflow\n");
        return -1;
    }
    int data = queue[front];
    if(front == rear){
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    return data;
}
void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear){
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);        
    display();
    printf("%d dequeued from queue\n", dequeue());
    display();
    enqueue(50);
    display();
    enqueue(60);
}