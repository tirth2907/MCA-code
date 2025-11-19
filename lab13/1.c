#include "stdio.h"
#include "stdlib.h"

struct pair
{
    int val;
    int priority;
};

#define MAX 100
struct pair pqueue[MAX];
int front=-1,rear=-1;
void enqueue(int p,int pr){
    if(rear == MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front == -1)
    {
        front = 0;
        rear = 0;
    } else {
        rear++;
    }
    pqueue[rear].val = p;
    pqueue[rear].priority = pr;
}

void dequeue(){
    if (rear == -1 || front > rear)
    {
        printf("Queue Underflow\n");
        return;
    }
    if(front == rear){
        front = -1;
        rear = -1;
        return;
    }
    int maxindex = front;
    for(int i=front+1;i<=rear;i++){
        if(pqueue[i].priority > pqueue [maxindex].priority){
            maxindex = i;
        }
    }
    printf("Dequeued element: val=%d, priority=%d\n",pqueue [maxindex].val,pqueue [maxindex].priority);
    for(int i=maxindex;i<rear;i++){
        pqueue[i]=pqueue[i+1];
    }
    rear--;
}
void display(){
    if (rear == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Priority Queue elements:\n");
    for(int i=front;i<=rear;i++){
        printf("val=%d, priority=%d\n",pqueue[i].val,pqueue[i].priority);
    }
}
int main()
{
    enqueue(10,2);
    enqueue(20,1);
    enqueue(30,3);
    dequeue();
    display();

    return 0;
}
