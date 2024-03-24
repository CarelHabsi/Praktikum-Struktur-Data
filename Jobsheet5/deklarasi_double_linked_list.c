#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct node {
    int data;
    struct node *next;
    struct node *back;
};

struct node *head = NULL;
struct node *tail = NULL;
struct node *current;

void printList() {
    struct node *temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main () {
    system("cls");
    current = (struct node *) malloc (sizeof (struct node));
    current->data = 1;
    current->next = NULL;
    current->back = NULL;
    head = tail = current;

    // Print the initial list
    printf("Initial List:\n");
    printList();

    return 0;
}