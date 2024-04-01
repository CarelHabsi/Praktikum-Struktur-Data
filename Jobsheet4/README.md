# Struktur Data Doubly Linked List dalam Bahasa C

## Pengantar
Doubly linked list adalah struktur data linier yang mirip dengan singly linked list, tetapi setiap node dalam doubly linked list memiliki dua pointer: satu untuk menunjuk ke node sebelumnya (prev) dan satu untuk menunjuk ke node berikutnya (next). Hal ini memungkinkan navigasi maju dan mundur dalam linked list.

## Konsep Dasar Doubly Linked List
Setiap node dalam doubly linked list terdiri dari tiga bagian utama:
1. **Data**: Menyimpan nilai atau informasi yang diinginkan.
2. **Pointer prev**: Menunjuk ke node sebelumnya dalam linked list.
3. **Pointer next**: Menunjuk ke node berikutnya dalam linked list.

## Alur Node dalam Doubly Linked List
![Alur Node Doubly Linked List](https://storage.googleapis.com/kotakode-prod-public/images/6c8785e1-fb53-49f6-a280-4a199a3c17d9-image.png)

- Setiap node memiliki dua pointer, yaitu pointer prev dan pointer next.
- Node pertama disebut sebagai *head* yang menunjuk ke node pertama dalam linked list.
- Node terakhir disebut sebagai *tail* yang menunjuk ke NULL pada pointer next-nya.

## Implementasi Doubly Linked List dalam Pemrograman C
Berikut adalah contoh implementasi doubly linked list dalam bahasa C:

```c
#include <stdio.h>
#include <stdlib.h>

// Struktur Node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Fungsi untuk menambahkan node baru di awal linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->prev = NULL;
    new_node->next = *head_ref;

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list dari depan
void printForward(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

// Fungsi untuk mencetak linked list dari belakang
void printBackward(struct Node* node) {
    while (node->next != NULL) {
        node = node->next;
    }

    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Menambahkan node-node baru di awal linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);

    // Mencetak linked list dari depan
    printf("Linked List (Forward): ");
    printForward(head);

    // Mencetak linked list dari belakang
    printf("Linked List (Backward): ");
    printBackward(head);

    return 0;
}
```

Dalam contoh di atas, kita menggunakan struktur Node dengan pointer **prev** dan **next** untuk merepresentasikan node dalam doubly linked list. Fungsi **insertAtBeginning** digunakan untuk menambahkan node baru di awal linked list, dan fungsi **printForward** dan **printBackward** digunakan untuk mencetak isi linked list dari depan dan belakang.
