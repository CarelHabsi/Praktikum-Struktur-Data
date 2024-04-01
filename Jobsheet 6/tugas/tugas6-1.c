#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

struct Student {
    char nim[10];
    char name[50];
    float grade;
};

struct Stack {
    struct Student data[MAX_SIZE];
    int top;
};

void initialize(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, struct Student student) {
    if (isFull(stack)) {
        printf("Stack is full. Cannot push data.\n");
        return;
    }
    stack->data[++stack->top] = student;
    printf("Data pushed successfully.\n");
}

struct Student pop(struct Stack* stack) {
    struct Student emptyStudent = {"", "", 0.0};
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop data.\n");
        return emptyStudent;
    }
    return stack->data[stack->top--];
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents:\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("NIM: %s, Name: %s, Grade: %.2f\n", stack->data[i].nim, stack->data[i].name, stack->data[i].grade);
    }
}

void sort(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot sort data.\n");
        return;
    }
    for (int i = 0; i <= stack->top; i++) {
        for (int j = i + 1; j <= stack->top; j++) {
            if (stack->data[i].grade > stack->data[j].grade) {
                struct Student temp = stack->data[i];
                stack->data[i] = stack->data[j];
                stack->data[j] = temp;
            }
        }
    }
    printf("Data sorted successfully.\n");
}

int main() {
    system("cls");
    struct Stack stack;
    initialize(&stack);

    int choice;
    struct Student student;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push data\n");
        printf("2. Pop data\n");
        printf("3. Display stack\n");
        printf("4. Sort data\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter NIM: ");
                scanf("%s", student.nim);
                printf("Enter name: ");
                scanf(" %[^\n]s", student.name);
                printf("Enter grade: ");
                scanf("%f", &student.grade);
                push(&stack, student);
                break;
            case 2:
                student = pop(&stack);
                if (strcmp(student.nim, "") != 0) {
                    printf("Popped data: NIM: %s, Name: %s, Grade: %.2f\n", student.nim, student.name, student.grade);
                }
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                sort(&stack);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}