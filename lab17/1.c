#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* first = NULL;

void insertInOrder(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (first == NULL || first->data >= data) {
        newNode->next = first;
        first = newNode;
    }
    else {
        struct Node* current = first;
        while (current->next != NULL && current->next->data < data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void displayList() {
    struct Node* temp = first;
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
    
}

int countNodes() {
    int count = 0;
    struct Node* temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteNode(int x)
{
    if (first == NULL) {
        printf("underflow\n");
        return;
    }

    struct Node *save = first;
    struct Node *pred = NULL;

    if (save->data == x) {
        first = save->next;
        free(save);
        return;
    }

    while (save != NULL && save->data != x) {
        pred = save;
        save = save->next;
    }

    if (save == NULL) {
        printf("Value %d not found in the list.\n", x);
        return;
    }

    pred->next = save->next;
    free(save);
}

void main()
{
    insertInOrder(30);
    insertInOrder(10);
    insertInOrder(20);
    insertInOrder(40);
    displayList();
    printf("Number of nodes: %d\n", countNodes());
    deleteNode(20);
    printf("After deletion:\n");
    displayList();
}