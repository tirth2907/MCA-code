#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int deque[MAX];
int front = -1, rear = -1;
void enqueue_front(int x){
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)){
        printf("Deque Overflow at front\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
     else if(front == 0){
        front = MAX - 1;
    } 
    else {
        front = front - 1;
    }
    deque[front] = x;
    printf("%d enqueued to front of deque\n", x);
}
void enqueue_rear(int x){
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)){
        printf("Deque Overflow at rear\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
     else if(rear == MAX - 1){
        rear = 0;
    }
     else {
        rear = rear + 1;
    }
    deque[rear] = x;
    printf("%d enqueued to rear of deque\n", x);
}
int dequeue_front(){
    if(front == -1){
        printf("Deque Underflow at front\n");
        return -1;
    }
    int data = deque[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }
     else if(front == MAX - 1){
        front = 0;
    }
     else {
        front = front + 1;
    }
    return data;
}
int dequeue_rear(){
    if(front == -1){
        printf("Deque Underflow at rear\n");
        return -1;
    }
    int data = deque[rear];
    if(front == rear){
        front = -1;
        rear = -1;
    }
     else if(rear == 0){
        rear = MAX - 1;
    }
     else {
        rear = rear - 1;
    }
    return data;
}
void display(){
    if(front == -1){
        printf("Deque is empty\n");
        return;
    }
    printf("Deque elements: ");
    int i = front;
    while(1){
        printf("%d ", deque[i]);
        if(i == rear){
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}
void main(){
    enqueue_rear(10);
    enqueue_rear(20);   
    enqueue_front(5);
    display();
    printf("%d dequeued from front of deque\n", dequeue_front());
    display();
    printf("%d dequeued from rear of deque\n", dequeue_rear());
    display();
    enqueue_front(1);
    display();
}
