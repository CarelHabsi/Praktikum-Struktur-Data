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
