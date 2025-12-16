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
    printf("Circular List: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int countNodes() {
    if (last == NULL)
        return 0;

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
        printf("Underflow\n");
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
        printf("Underflow\n");
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

void deleteAtN(int x) {
    if (last == NULL) {
        printf("Underflow\n");
        return;
    }

    struct Node* current = last->next;
    struct Node* prev = last;

    if (current->data == x) {
        if (current == last) {
            free(current);
            last = NULL;
        } else {
            prev->next = current->next;
            free(current);
        }
        return;
    }

    do {
        if (current->data == x) {
            prev->next = current->next;

            if (current == last)
                last = prev;

            free(current);
            return;
        }
        prev = current;
        current = current->next;

    } while (current != last->next);

    printf("Node %d not found.\n", x);
}

int main() {

    insertAtBeginning(10);
    insertAtEnd(20);
    insertAtBeginning(5);
    insertAtEnd(30);
    insertAtBeginning(1);

    displayList();

    deleteLastNode();
    deleteFirstNode();
    deleteAtN(20);

    printf("List after deletions: ");
    displayList();

    printf("Total nodes: %d\n", countNodes());

    return 0;
}