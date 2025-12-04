// Write a menu driven program to implement following operations on the 
// Doubly Linked List. 
// • Insert a node in doubly linked list 
// • Delete a node in doubly linked list 
// • Display the list 
// • Count the number of nodes
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* lptr;
    struct Node* rptr;
};

struct Node* first = NULL;
struct node* l = NULL;
struct node* r = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lptr = NULL;
    newNode->rptr = first;
    if (first != NULL) {
        first->lptr = newNode;
    }
    first = newNode;
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->rptr = NULL;
    if (first == NULL) {
        newNode->lptr = NULL;
        first = newNode;
    } else {
        struct Node* temp = first;
        while (temp->rptr != NULL) {
            temp = temp->rptr;
        }
        temp->rptr = newNode;
        newNode->lptr = temp;
    }
}

void displayList() {
    struct Node* temp = first;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->rptr;
    }
}

int countNodes() {
    int count = 0;
    struct Node* temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->rptr;
    }
    return count;
}

void deleteFirstNode() {
    if (first == NULL) {
        printf("underflow\n");
        return;
    }
    struct Node* temp = first;
    first = first->rptr;
    if (first != NULL) {
        first->lptr = NULL;
    }
    free(temp);
}

void deleteLastNode() {
    if (first == NULL) {
        printf("underflow\n");
        return;
    }
    if (first->rptr == NULL) {
        free(first);
        first = NULL;
        return;
    }
    struct Node* temp = first;
    while (temp->rptr != NULL) {
        temp = temp->rptr;
    }
    temp->lptr->rptr = NULL;
    free(temp);
}

void deleteAtN(int x)
{
    if (first == NULL) {
        printf("underflow\n");
        return;
    }

    struct Node *current = first;
    if (current->data == x) {
        first = current->rptr;
        if (first != NULL) {
            first->lptr = NULL;
        }
        free(current);
        return;
    }

   
    while (current != NULL) {
        if (current->data == x) {
            if (current->rptr != NULL) {
                current->rptr->lptr = current->lptr;
            }
            if (current->lptr != NULL) {
                current->lptr->rptr = current->rptr;
            }
            free(current);
            return;
        }
        current = current->rptr;
    }

    printf("Node with value %d not found.\n", x);
}

int main(void) {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);
    insertAtBeginning(1);  
    displayList();
    printf("\n");
    deleteLastNode();
    deleteFirstNode();
    printf("List after deletions:\n");
    displayList();
    printf("Total nodes: %d\n", countNodes());
    return 0;
}
