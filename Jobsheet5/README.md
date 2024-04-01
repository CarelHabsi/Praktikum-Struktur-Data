# Konsep Circular Linked List dan Circular Doubly Linked List dalam Bahasa C

## Pengantar
Circular linked list dan circular doubly linked list adalah struktur data linier yang memiliki karakteristik khusus di mana node terakhir menunjuk kembali ke node pertama, membentuk lingkaran atau sirkuit. Circular doubly linked list mirip dengan circular linked list, tetapi setiap node dalam circular doubly linked list memiliki dua pointer: satu untuk menunjuk ke node sebelumnya (prev) dan satu untuk menunjuk ke node berikutnya (next).

## Circular Linked List
Circular linked list adalah struktur data linier di mana setiap node memiliki pointer yang menunjuk ke node berikutnya, dan node terakhir menunjuk kembali ke node pertama, membentuk lingkaran.

### Alur Node Circular Linked List
![Alur Node Circular Linked List](https://slideplayer.info/slide/12700172/76/images/2/Circular+Single+Linked+list+Circular+Double+Linked+list.jpg)

- Setiap node memiliki satu pointer yang menunjuk ke node berikutnya.
- Node terakhir (tail) menunjuk kembali ke node pertama (head), membentuk lingkaran.

### Implementasi Circular Linked List dalam Pemrograman C
Berikut adalah contoh implementasi circular linked list dalam bahasa C:

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Fungsi-fungsi lainnya (seperti insert, delete, dll.) dapat ditambahkan sesuai kebutuhan
```

### Circular Doubly Linked List
Circular doubly linked list adalah struktur data linier di mana setiap node memiliki dua pointer: satu untuk menunjuk ke node sebelumnya (prev) dan satu untuk menunjuk ke node berikutnya (next). Node terakhir (tail) menunjuk kembali ke node pertama (head), membentuk lingkaran.

## Alur Node Circular Doubly Linked List

Setiap node memiliki dua pointer, yaitu pointer prev dan pointer next.
Node pertama disebut sebagai head yang menunjuk ke node pertama dalam linked list.
Node terakhir disebut sebagai tail yang menunjuk kembali ke node pertama.

## Implementasi Circular Doubly Linked List dalam Pemrograman C
Berikut adalah contoh implementasi circular doubly linked list dalam bahasa C:

```c
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Fungsi-fungsi lainnya (seperti insert, delete, dll.) dapat ditambahkan sesuai kebutuhan
```
#### Perbedaan Antara Circular Linked List dan Circular Doubly Linked List

# 1. Struktur Node:

- Circular linked list: Setiap node memiliki satu pointer (next).
- Circular doubly linked list: Setiap node memiliki dua pointer (prev dan next).

# 2. Navigasi:

- Circular linked list memungkinkan navigasi maju tanpa batas, karena node terakhir menunjuk kembali ke node pertama.
- Circular doubly linked list memungkinkan navigasi maju dan mundur (dari depan ke belakang dan sebaliknya).

# 3. Pemanfaatan Memori:

- Circular linked list dapat lebih efisien dalam penggunaan memori karena hanya memiliki satu pointer per node.
- Circular doubly linked list membutuhkan lebih banyak ruang memori karena setiap node memiliki dua pointer.
