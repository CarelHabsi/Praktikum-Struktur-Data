#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>
 
typedef struct LinkedList { 
    int data; 
    struct LinkedList* next; 
} node; 
 
int main() 
{
    system("cls");
    node* head = NULL; 
    node* second = NULL; 
    node* third = NULL; 
 
    head = (node*)malloc(sizeof(node)); 
    second = (node*)malloc(sizeof(node)); 
    third = (node*)malloc(sizeof(node)); 
 
    head->data = 1;
    head->next = second;
 
    second->data = 2;
    second->next = third; 
 
    third->data = 3;
    third->next = NULL; 
 
    printf("%d ", head->data); 
    printf("%d ", second->data); 
    printf("%d ", third->data); 
 
    return 0;
}