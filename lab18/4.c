#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* first = NULL;

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if (first == NULL) {
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList() {
    struct Node* temp = first;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

void reverseList() {
    struct Node* prev = NULL;
    struct Node* current = first;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;  
        current->next = prev;  
        prev = current;        
        current = next;       
    }
    first = prev;  
}

int main(void) {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Original List:\n");
    displayList();

    reverseList();

    printf("\nReversed List:\n");
    displayList();

    return 0;
}
