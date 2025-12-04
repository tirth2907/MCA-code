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

void sortList() {
    if (first == NULL || first->next == NULL) {
        return; // List is empty or has only one element
    }

    struct Node* i;
    struct Node* j;
    int temp;

    for (i = first; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                // Swap data
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}

int main(void) {
    insertAtEnd(30);
    insertAtEnd(10);
    insertAtEnd(20);
    insertAtEnd(5);
    insertAtEnd(15);

    printf("Original list:\n");
    displayList();

    sortList();

    printf("\nSorted list:\n");
    displayList();

    return 0;
}