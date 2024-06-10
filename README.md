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

<h2 align="center">Pengenalan Praktikum Struktur Data</h2>

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
