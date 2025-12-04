#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* first = NULL;
void deleteFirstNode() {
    if (first == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    struct Node* temp = first;
    first = first->next;
    free(temp);
    printf("First node deleted.\n");
}
void deleteLastNode() {
    if (first == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }
    if (first->next == NULL) {
        free(first);
        first = NULL;
        printf("Last node deleted.\n");
        return;
    }
    struct Node* temp = first;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    printf("Last node deleted.\n");
}

void deleteAtN(int x)
{
    if (first == NULL) {
        printf("List is empty. No node to delete.\n");
        return;
    }

    struct Node *save = first;
    struct Node *pred = NULL;

    if (save->data == x) {
        first = save->next;
        free(save);
        printf("Node with value %d deleted.\n", x);
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

    /* Unlink and free the node */
    pred->next = save->next;
    free(save);
    printf("Node with value %d deleted.\n", x);
}

void displayList() {
    if (first == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = first;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

