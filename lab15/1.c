#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* first = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = first;
    first = newNode;
}

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

int countNodes() {
    int count = 0;
    struct Node* temp = first;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void deleteFirstNode() {
    if (first == NULL) {
        printf("underflow\n");
        return;
    }
    struct Node* temp = first;
    first = first->next;
    free(temp);
}
void deleteLastNode() {
    if (first == NULL) {
        printf("underflow\n");
        return;
    }
    if (first->next == NULL) {
        free(first);
        first = NULL;
        return;
    }
    struct Node* temp = first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteAtN(int x)
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
    deleteAtN(20);
    displayList();
    printf("Number of nodes: %d\n", countNodes());
    return 0;
}