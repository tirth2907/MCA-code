#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* last = NULL;

void insertAtBeginning(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        newNode->next = newNode; 
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
}

void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if (last == NULL) {
        last = newNode;
        newNode->next = newNode; 
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode; 
    }
}

void displayList() {
    if (last == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = last->next; 
    do {
        printf("%d\n", temp->data);
        temp = temp->next;
    } while (temp != last->next);
}

int countNodes() {
    if (last == NULL) {
        return 0;
    }
    int count = 0;
    struct Node* temp = last->next; 
    do {
        count++;
        temp = temp->next;
    } while (temp != last->next);
    return count;
}

void deleteFirstNode() {
    if (last == NULL) {
        printf("underflow\n");
        return;
    }
    struct Node* first = last->next;
    if (first == last) {
        free(first);
        last = NULL;
    } else {
        last->next = first->next;
        free(first);
    }
}

void deleteLastNode() {
    if (last == NULL) {
        printf("underflow\n");
        return;
    }
    struct Node* first = last->next;
    if (first == last) {
        free(last);
        last = NULL;
    } else {
        struct Node* temp = first;
        while (temp->next != last) {
            temp = temp->next;
        }
        temp->next = last->next;
        free(last);
        last = temp;
    }
}

void deleteAtN(int x)
{
    if (last == NULL) {
        printf("underflow\n");
        return;
    }
    struct Node* first = last->next;
    struct Node *save = first;
    struct Node *pred = last;

    do {
        if (save->data == x) {
            if (save == first) {
                last->next = first->next;
            } else if (save == last) {
                pred->next = last->next;
                last = pred;
            } else {
                pred->next = save->next;
            }
            free(save);
            return;
        }
        pred = save;
        save = save->next;
    } while (save != first);

    printf("Value %d not found in the list.\n", x);
}

void main(void) {
    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);

    printf("Initial list:\n");
    displayList();

    deleteLastNode();
    deleteFirstNode();
    deleteAtN(20);

    printf("\nList after deletions:\n");
    displayList();

    printf("Total nodes: %d\n", countNodes());

}

