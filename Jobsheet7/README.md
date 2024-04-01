# Konsep Queue dalam Bahasa C

## Pengantar
Queue adalah struktur data linier yang mengikuti prinsip FIFO (First In, First Out), artinya elemen pertama yang dimasukkan ke dalam queue akan menjadi elemen pertama yang keluar. Operasi pada queue meliputi enqueue (menambahkan elemen ke queue) dan dequeue (menghapus elemen dari queue).

## Konsep Dasar Queue
Queue terdiri dari dua operasi utama:
1. **Enqueue**: Menambahkan elemen ke dalam queue.
2. **Dequeue**: Menghapus elemen dari depan queue.

## Alur Node dalam Queue
![Alur Node Queue](https://cdn.programiz.com/sites/tutorial2program/files/queue.jpg)

- Setiap node dalam queue memiliki dua bagian utama: data (nilai yang disimpan) dan pointer (alamat memori node berikutnya).
- Elemen baru ditambahkan ke belakang queue.
- Elemen di depan queue adalah elemen yang paling lama ditambahkan dan yang akan dihapus saat operasi dequeue dilakukan.

## Implementasi Queue dalam Pemrograman C
Berikut adalah contoh implementasi queue menggunakan array dalam bahasa C:

```c
#include <stdio.h>
#define MAX_SIZE 100 // Ukuran maksimum queue

// Struktur Queue
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Inisialisasi queue
void initQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Fungsi untuk mengecek apakah queue kosong
int isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Fungsi untuk mengecek apakah queue penuh
int isFull(struct Queue* queue) {
    return queue->rear == MAX_SIZE - 1;
}

// Fungsi untuk menambahkan elemen ke dalam queue (enqueue)
void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(queue)) {
        queue->front = 0;
    }
    queue->rear++;
    queue->items[queue->rear] = item;
}

// Fungsi untuk menghapus elemen dari depan queue (dequeue)
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue->items[queue->front];
    queue->front++;
    if (queue->front > queue->rear) {
        queue->front = queue->rear = -1;
    }
    return item;
}

// Fungsi untuk melihat elemen di depan queue (peek)
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    return queue->items[queue->front];
}

int main() {
    struct Queue queue;
    initQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Elemen di depan queue: %d\n", peek(&queue));

    printf("Elemen yang dihapus: %d\n", dequeue(&queue));
    printf("Elemen di depan queue setelah dequeue: %d\n", peek(&queue));

    return 0;
}
```

Dalam contoh di atas, kita menggunakan array untuk menyimpan elemen-elemen queue. Fungsi-fungsi seperti enqueue, dequeue, peek, isEmpty, dan isFull digunakan untuk operasi-operasi dasar pada queue.
