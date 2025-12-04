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

void removeDuplicates() {
    struct Node* current = first;
    struct Node* nextNext;

    if (current == NULL) {
        return;
    }

    while (current->next != NULL) {
        if (current->data == current->next->data) {
            nextNext = current->next->next;
            free(current->next);
            current->next = nextNext;
        } else {
            current = current->next;
        }
    }
}

int main(void) {
    insertAtEnd(1);
    insertAtEnd(1);
    insertAtEnd(6);
    insertAtEnd(13);
    insertAtEnd(13);
    insertAtEnd(13);
    insertAtEnd(27);
    insertAtEnd(27);

    printf("Original list:\n");
    displayList();

    removeDuplicates();

    printf("List after removing duplicates:\n");
    displayList();

    return 0;
}
