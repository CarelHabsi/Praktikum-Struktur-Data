#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_SIZE 100

typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

void initStack(Stack *stack) {
    stack->top = -1;
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

int isFull(Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(Stack *stack, char item) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->data[++stack->top] = item;
}

char pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0';
    }
    return stack->data[stack->top--];
}

void reverseString(char *str) {
    Stack stack;
    int i;

    initStack(&stack);

    for (i = 0; i < strlen(str); i++) {
        push(&stack, str[i]);
    }

    for (i = 0; i < strlen(str); i++) {
        str[i] = pop(&stack);
    }
}

int main() {
    system("cls");
    int choice;
    char word[MAX_SIZE];

    do {
        printf("Menu:\n");
        printf("1) Input Kata\n");
        printf("2) Balik Kata\n");
        printf("3) Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Masukkan kata: ");
                scanf("%s", word);
                break;
            case 2:
                reverseString(word);
                printf("Kata terbalik: %s\n", word);
                break;
            case 3:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Menu tidak valid\n");
                break;
        }
    } while (choice != 3);

    return 0;
}