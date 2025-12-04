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

struct Node* copyList() {
    if (first == NULL) {
        return NULL; 
    }

    struct Node* newHead = NULL;
    struct Node* newTail = NULL;
    struct Node* current = first;

    while (current != NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = current->data;
        newNode->next = NULL;

        if (newHead == NULL) {
            newHead = newNode; 
            newTail = newNode; 
        } else {
            newTail->next = newNode; 
            newTail = newNode;       
        }
        current = current->next;
    }
    return newHead;
}

int main(void) {
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);

    printf("Original List:\n");
    displayList();

    struct Node* copiedList = copyList();

    printf("\nCopied List:\n");
    struct Node* temp = copiedList;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }

    return 0;
}
