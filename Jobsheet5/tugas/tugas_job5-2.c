#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Car {
    char noPlat[20];
    char merkMobil[20];
    char namaPemilik[50];
    struct Car* next;
};

void enqueue(struct Car** head, struct Car** tail, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    strcpy(newCar->noPlat, noPlat);
    strcpy(newCar->merkMobil, merkMobil);
    strcpy(newCar->namaPemilik, namaPemilik);
    newCar->next = NULL;

    if (*head == NULL) {
        *head = newCar;
        *tail = newCar;
    } else {
        (*tail)->next = newCar;
        *tail = newCar;
    }

    printf("Car added to the queue.\n");
}

void dequeue(struct Car** head, struct Car** tail) {
    if (*head == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Car* temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Car removed from the queue.\n");
    }
}

void displayQueue(struct Car* head) {
    if (head == NULL) {
        printf("Queue is empty.\n");
    } else {
        struct Car* current = head;
        printf("Cars in the queue:\n");
        while (current != NULL) {
            printf("License Plate: %s\n", current->noPlat);
            printf("Car Brand: %s\n", current->merkMobil);
            printf("Owner's Name: %s\n", current->namaPemilik);
            printf("--------------------\n");
            current = current->next;
        }
    }
}

void freeQueue(struct Car* head) {
    struct Car* current = head;
    while (current != NULL) {
        struct Car* temp = current;
        current = current->next;
        free(temp);
    }
}

void addCarToBeginning(struct Car** head, struct Car** tail, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    strcpy(newCar->noPlat, noPlat);
    strcpy(newCar->merkMobil, merkMobil);
    strcpy(newCar->namaPemilik, namaPemilik);
    newCar->next = *head;

    if (*head == NULL) {
        *head = newCar;
        *tail = newCar;
    } else {
        *head = newCar;
    }

    printf("Car added to the beginning of the queue.\n");
}

void addCarToEnd(struct Car** head, struct Car** tail, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    strcpy(newCar->noPlat, noPlat);
    strcpy(newCar->merkMobil, merkMobil);
    strcpy(newCar->namaPemilik, namaPemilik);
    newCar->next = NULL;

    if (*head == NULL) {
        *head = newCar;
        *tail = newCar;
    } else {
        (*tail)->next = newCar;
        *tail = newCar;
    }

    printf("Car added to the end of the queue.\n");
}

void addCarAtPosition(struct Car** head, struct Car** tail, char noPlat[], char merkMobil[], char namaPemilik[], int position) {
    struct Car* newCar = (struct Car*)malloc(sizeof(struct Car));
    strcpy(newCar->noPlat, noPlat);
    strcpy(newCar->merkMobil, merkMobil);
    strcpy(newCar->namaPemilik, namaPemilik);
    newCar->next = NULL;

    if (*head == NULL) {
        *head = newCar;
        *tail = newCar;
    } else if (position == 0) {
        newCar->next = *head;
        *head = newCar;
    } else {
        struct Car* current = *head;
        int count = 0;
        while (current != NULL && count < position - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Invalid position.\n");
            return;
        }
        newCar->next = current->next;
        current->next = newCar;
    }

    printf("Car added at position %d in the queue.\n", position);
}

void removeAllCars(struct Car** head, struct Car** tail) {
    struct Car* current = *head;
    while (current != NULL) {
        struct Car* temp = current;
        current = current->next;
        free(temp);
    }
    *head = NULL;
    *tail = NULL;
    printf("All cars removed from the queue.\n");
}

int main() {
    system("cls");
    struct Car* head = NULL;
    struct Car* tail = NULL;
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Add a car to the queue\n");
        printf("2. Remove a car from the queue\n");
        printf("3. Display the cars in the queue\n");
        printf("4. Add a car to the beginning of the queue\n");
        printf("5. Add a car to the end of the queue\n");
        printf("6. Add a car at a specific position in the queue\n");
        printf("7. Remove all cars from the queue\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Enter license plate: ");
                scanf("%s", noPlat);
                printf("Enter car brand: ");
                scanf("%s", merkMobil);
                printf("Enter owner's name: ");
                scanf("%s", namaPemilik);
                enqueue(&head, &tail, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 2: {
                dequeue(&head, &tail);
                break;
            }
            case 3: {
                displayQueue(head);
                break;
            }
            case 4: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Enter license plate: ");
                scanf("%s", noPlat);
                printf("Enter car brand: ");
                scanf("%s", merkMobil);
                printf("Enter owner's name: ");
                scanf("%s", namaPemilik);
                addCarToBeginning(&head, &tail, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 5: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Enter license plate: ");
                scanf("%s", noPlat);
                printf("Enter car brand: ");
                scanf("%s", merkMobil);
                printf("Enter owner's name: ");
                scanf("%s", namaPemilik);
                addCarToEnd(&head, &tail, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 6: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                int position;
                printf("Enter license plate: ");
                scanf("%s", noPlat);
                printf("Enter car brand: ");
                scanf("%s", merkMobil);
                printf("Enter owner's name: ");
                scanf("%s", namaPemilik);
                printf("Enter position: ");
                scanf("%d", &position);
                addCarAtPosition(&head, &tail, noPlat, merkMobil, namaPemilik, position);
                break;
            }
            case 7: {
                removeAllCars(&head, &tail);
                break;
            }
            case 8: {
                freeQueue(head);
                return 0;
            }
            default: {
                printf("Invalid choice. Please try again.\n");
                break;
            }
        }
    } while (1);

    return 0;
}