#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* buatNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Alokasi memori gagal!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void sisipkanNode(Node** head, int data) {
    Node* newNode = buatNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void tampilkanList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void bebaskanList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

Node* generateFibonacci(int n) {
    Node* head = NULL;
    if (n >= 1) {
        sisipkanNode(&head, 0);
    }
    if (n >= 2) {
        sisipkanNode(&head, 1);
    }
    if (n >= 3) {
        Node* prev = head;
        Node* curr = head->next;
        for (int i = 3; i <= n; i++) {
            int nextFib = prev->data + curr->data;
            sisipkanNode(&head, nextFib);
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

int main() {
    system("cls");
    int n;
    printf("Masukkan nilai n: ");
    scanf("%d", &n);

    Node* fibonacciList = generateFibonacci(n);
    printf("Deret Fibonacci: ");
    tampilkanList(fibonacciList);

    bebaskanList(fibonacciList);

    return 0;
}