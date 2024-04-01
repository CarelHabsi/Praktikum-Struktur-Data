# Struktur Data Linked List dalam Bahasa C

## Pengantar
Linked list adalah struktur data linier yang terdiri dari sekelompok node yang terhubung satu sama lain melalui pointer. Setiap node memiliki dua bagian, yaitu data atau nilai yang disimpan dan pointer yang menunjukkan ke node berikutnya dalam linked list.

## Konsep Dasar Linked List
Linked list dapat dibagi menjadi dua jenis utama:
1. **Singly Linked List**: Setiap node memiliki satu pointer yang menunjuk ke node berikutnya.
2. **Doubly Linked List**: Setiap node memiliki dua pointer, yaitu pointer yang menunjuk ke node sebelumnya dan pointer yang menunjuk ke node berikutnya.

## Alur Node dalam Linked List
![Alur Node Linked List](https://raw.githubusercontent.com/yourusername/yourrepositoryname/main/linkedListFlow.png)

- Setiap node dalam linked list terdiri dari dua bagian utama: data (nilai yang disimpan) dan pointer (alamat memori node berikutnya).
- Node pertama disebut sebagai *head* yang menunjuk ke node pertama dalam linked list.
- Node terakhir memiliki pointer bernilai NULL untuk menandakan akhir dari linked list.

## Penerapan Sederhana dalam Pemrograman C
Berikut adalah contoh implementasi singly linked list sederhana dalam bahasa C:

```c
#include <stdio.h>
#include <stdlib.h>

// Struktur Node
struct Node {
    int data;
    struct Node* next;
};

// Fungsi untuk menambahkan node baru di awal linked list
void insertAtBeginning(struct Node** head_ref, int new_data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Fungsi untuk mencetak linked list
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    // Menambahkan node-node baru di awal linked list
    insertAtBeginning(&head, 3);
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 7);

    // Mencetak linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}
```

Dalam contoh di atas, kita menggunakan struktur Node untuk merepresentasikan node dalam linked list. Fungsi insertAtBeginning digunakan untuk menambahkan node baru di awal linked list, dan fungsi printList digunakan untuk mencetak isi linked list.
