# 👋 Halo, Selamat Datang di Repository Praktikum Struktur Data Saya

## 📋 Deskripsi
Repository ini merupakan arsip pengumpulan tugas saya selama satu semester pada matakuliah Praktikum Struktur Data yang dibimbing oleh dosen kami yakni Randi Proska Sandra, S.Pd, M.Sc. Tugas pada repository ini diperuntukkan mahasiswa Informatika agar memahami konsep struktur data pada pemrograman terkhusus pada pemrograman bahasa C.

## 【 Daftar Jobsheet 】
- [Jobsheet 1](#jobsheet-1)
- [Jobsheet 2](#jobsheet-2)
- [Jobsheet 3](#jobsheet-3)
- [Jobsheet 4](#jobsheet-4)
- [Jobsheet 5](#jobsheet-5)
- [Jobsheet 6](#jobsheet-6)
- [Jobsheet 7](#jobsheet-7)
- [Jobsheet 8](#jobsheet-8)
- [Jobsheet 9](#jobsheet-9)
- [Jobsheet 10](#jobsheet-10)
- [Jobsheet 11](#jobsheet-11)
- [Jobsheet 12](#jobsheet-12)
- [Jobsheet 13](#jobsheet-13)

<div id="jobsheet-1">
  <h1>Jobsheet 1</h1>
</div>

<h1 align="center">Pengenalan Praktikum Struktur Data</h1>

## Pengantar
Struktur data adalah cara untuk menyimpan, mengatur, dan mengakses data dengan efisien. Dalam praktikum ini, kita akan mempelajari struktur data sederhana seperti array dan record, serta struktur data majemuk seperti Linear (stack, queue, list, multilist) dan Non-Linier (pohon biner dan graph).

## Struktur Data Sederhana
### 1. Array
Array adalah kumpulan elemen data yang disimpan secara berurutan dalam memori komputer. Setiap elemen memiliki indeks yang memungkinkan akses langsung ke elemen tersebut.

### 2. Record
Record adalah kumpulan data yang terdiri dari beberapa field atau atribut yang memiliki tipe data yang berbeda-beda. Setiap field dalam record dapat diakses secara terpisah.

## Struktur Data Majemuk
### 1. Linear Data Structures
#### - Stack
Stack adalah struktur data LIFO (Last In, First Out) yang mendukung operasi push (menambahkan elemen) dan pop (menghapus elemen). Elemen yang terakhir dimasukkan ke dalam stack akan menjadi elemen pertama yang dihapus.

#### - Queue
Queue adalah struktur data FIFO (First In, First Out) yang mendukung operasi enqueue (menambahkan elemen) dan dequeue (menghapus elemen). Elemen yang pertama dimasukkan ke dalam queue akan menjadi elemen pertama yang dihapus.

#### - List
List adalah kumpulan elemen data yang diatur secara linier. Terdapat dua jenis list, yaitu linked list dan array list, yang memiliki cara penyimpanan dan akses data yang berbeda.

#### - Multilist
Multilist adalah struktur data yang mengorganisir elemen data dalam bentuk graf terarah dengan beberapa jenis edge atau sisi.

### 2. Non-Linear Data Structures
#### - Binary Tree
Binary Tree adalah struktur data hierarkis yang terdiri dari simpul-simpul (nodes) yang memiliki dua anak, yaitu anak kiri dan anak kanan.

#### - Graph
Graph adalah struktur data yang terdiri dari kumpulan simpul (nodes) yang terhubung oleh edge atau sisi. Graph dapat digunakan untuk merepresentasikan hubungan antar objek.

<div id="jobsheet-2">
  <h1>Jobsheet 2</h1>
</div>

<h2 align="center">Array, Pointer,  Structure</h2>

# Materi Praktikum Struktur Data

## Pengantar
Struktur data adalah cara untuk menyimpan, mengatur, dan mengakses data dengan efisien. Dalam praktikum ini, kita akan mempelajari struktur data sederhana seperti array dan record, serta struktur data majemuk seperti Linear (stack, queue, list, multilist) dan Non-Linier (pohon biner dan graph).

## Konsep Dasar Pemrograman dalam Bahasa C

### Array
Array adalah struktur data yang terdiri dari kumpulan elemen dengan tipe data yang sama yang disimpan secara berurutan dalam memori komputer. Setiap elemen dalam array dapat diakses menggunakan indeksnya. Contoh penggunaan array dalam C:

```c
int numbers[5] = {1, 2, 3, 4, 5}; // Mendefinisikan array numbers dengan 5 elemen
int x = numbers[2]; // Mengakses elemen ke-3 dari array numbers
```

### Pointer
Pointer adalah variabel yang menyimpan alamat memori dari variabel lain. Dengan menggunakan pointer, kita dapat mengakses dan memanipulasi nilai variabel secara langsung di dalam memori. Contoh penggunaan pointer dalam C:

```c
int a = 10;
int *ptr; // Mendefinisikan pointer ptr
ptr = &a; // Mengisi ptr dengan alamat memori variabel a
printf("Nilai a: %d\n", *ptr); // Mengakses nilai a melalui pointer ptr
```

### Structure (Struktur)
Structure adalah cara untuk menggabungkan beberapa tipe data menjadi satu tipe data baru yang lebih kompleks. Struktur digunakan untuk merepresentasikan objek dengan atribut-atributnya. Contoh penggunaan structure dalam C:

```c
struct Mahasiswa {
    char nama[50];
    int umur;
    float ipk;
};

struct Mahasiswa mhs1; // Mendefinisikan variabel mhs1 dengan tipe data struct Mahasiswa
strcpy(mhs1.nama, "John Doe"); // Mengisi nilai atribut nama pada mhs1
mhs1.umur = 20;
mhs1.ipk = 3.75;
```

### Abstract Data Type (ADT)
ADT adalah konsep yang menggabungkan struktur data dengan operasi-operasi yang dapat dilakukan terhadap struktur data tersebut. ADT tidak mengikat implementasi struktur data tertentu, sehingga memungkinkan penggunaan berbagai teknik pemrograman. Contoh ADT dalam C adalah implementasi stack:

```c
// Definisi ADT Stack
#define MAX_SIZE 100
typedef struct {
    int items[MAX_SIZE];
    int top;
} Stack;

// Operasi-operasi pada Stack
void push(Stack *s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack penuh\n");
    } else {
        s->top++;
        s->items[s->top] = value;
    }
}

int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack kosong\n");
        return -1;
    } else {
        int temp = s->items[s->top];
        s->top--;
        return temp;
    }
}
```

<div id="jobsheet-3">
  <h1>Jobsheet 3</h1>
</div>

<h1 align="center">Single Linked List</h1>

# Struktur Data Linked List dalam Bahasa C

## Pengantar
Linked list adalah struktur data linier yang terdiri dari sekelompok node yang terhubung satu sama lain melalui pointer. Setiap node memiliki dua bagian, yaitu data atau nilai yang disimpan dan pointer yang menunjukkan ke node berikutnya dalam linked list.

## Konsep Dasar Linked List
Linked list dapat dibagi menjadi dua jenis utama:
1. **Singly Linked List**: Setiap node memiliki satu pointer yang menunjuk ke node berikutnya.
2. **Doubly Linked List**: Setiap node memiliki dua pointer, yaitu pointer yang menunjuk ke node sebelumnya dan pointer yang menunjuk ke node berikutnya.

## Alur Node dalam Linked List
![Alur Node Linked List](https://www.simplilearn.com/ice9/free_resources_article_thumb/Types-of-Linked-List/types_of_linked_list-singly-linked-list-img1.PNG)

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

<div id="jobsheet-4">
  <h1>Jobsheet 4</h1>
</div>

<h1 align="center">Doubly Linked List</h1>

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

<div id="jobsheet-5">
  <h1>Jobsheet 5</h1>
</div>

<h1 align="center">Double and Circular Linked List</h1>

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

<div id="jobsheet-6">
  <h1>Jobsheet 6</h1>
</div>

<h1 align="center">Stack</h1>

# Konsep Stack dalam Bahasa C

## Pengantar
Stack adalah struktur data linier yang mengikuti prinsip LIFO (Last In, First Out), artinya elemen terakhir yang dimasukkan ke dalam stack akan menjadi elemen pertama yang keluar. Operasi pada stack meliputi push (menambahkan elemen ke stack) dan pop (menghapus elemen dari stack).

## Konsep Dasar Stack
Stack terdiri dari tiga operasi utama:
1. **Push**: Menambahkan elemen ke dalam stack.
2. **Pop**: Menghapus elemen teratas dari stack.
3. **Peek**: Melihat nilai elemen teratas dari stack tanpa menghapusnya.

## Alur Node dalam Stack
![Alur Node Stack](https://ids.ac.id/wp-content/uploads/2023/04/2-1024x576.jpg)

- Setiap node dalam stack memiliki dua bagian utama: data (nilai yang disimpan) dan pointer (alamat memori node sebelumnya).
- Elemen terbaru ditambahkan ke atas stack.
- Elemen teratas (top) adalah elemen yang paling baru ditambahkan dan yang akan dihapus saat operasi pop dilakukan.

## Implementasi Stack dalam Pemrograman C
Berikut adalah contoh implementasi stack menggunakan array dalam bahasa C:

```c
#include <stdio.h>
#define MAX_SIZE 100 // Ukuran maksimum stack

// Struktur Stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Inisialisasi stack
void initStack(struct Stack* stack) {
    stack->top = -1;
}

// Fungsi untuk mengecek apakah stack kosong
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Fungsi untuk mengecek apakah stack penuh
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan elemen ke dalam stack (push)
void push(struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->items[++stack->top] = item;
}

// Fungsi untuk menghapus elemen teratas dari stack (pop)
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->items[stack->top--];
}

// Fungsi untuk melihat elemen teratas dari stack (peek)
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->items[stack->top];
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Elemen teratas: %d\n", peek(&stack));

    printf("Elemen yang dihapus: %d\n", pop(&stack));
    printf("Elemen teratas setelah pop: %d\n", peek(&stack));

    return 0;
}
```

Dalam contoh di atas, kita menggunakan array untuk menyimpan elemen-elemen stack. Fungsi-fungsi seperti push, pop, peek, isEmpty, dan isFull digunakan untuk operasi-operasi dasar pada stack.
