#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// Struktur untuk sebuah buku
typedef struct Buku {
    char judul[100];
    char pengarang[100];
    int tahun;
    struct Buku* prev;
    struct Buku* next;
} Buku;

// Fungsi untuk membuat node buku baru
Buku* buatBuku(char judul[], char pengarang[], int tahun) {
    Buku* bukuBaru = (Buku*)malloc(sizeof(Buku));
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->pengarang, pengarang);
    bukuBaru->tahun = tahun;
    bukuBaru->prev = NULL;
    bukuBaru->next = NULL;
    return bukuBaru;
}

// Fungsi untuk menyisipkan sebuah buku di awal daftar
void sisipkanBukuDiAwal(Buku** head, char judul[], char pengarang[], int tahun) {
    Buku* bukuBaru = buatBuku(judul, pengarang, tahun);
    if (*head == NULL) {
        *head = bukuBaru;
    } else {
        bukuBaru->next = *head;
        (*head)->prev = bukuBaru;
        *head = bukuBaru;
    }
}

// Fungsi untuk menyisipkan sebuah buku di akhir daftar
void sisipkanBukuDiAkhir(Buku** head, char judul[], char pengarang[], int tahun) {
    Buku* bukuBaru = buatBuku(judul, pengarang, tahun);
    if (*head == NULL) {
        *head = bukuBaru;
    } else {
        Buku* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = bukuBaru;
        bukuBaru->prev = temp;
    }
}

// Fungsi untuk menghapus sebuah buku dari daftar berdasarkan judul
void hapusBukuBerdasarkanJudul(Buku** head, char judul[]) {
    if (*head == NULL) {
        printf("Daftar kosong.\n");
        return;
    }

    Buku* temp = *head;
    while (temp != NULL) {
        if (strcmp(temp->judul, judul) == 0) {
            if (temp->prev == NULL) {
                *head = temp->next;
                if (*head != NULL) {
                    (*head)->prev = NULL;
                }
            } else {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
            }
            free(temp);
            printf("Buku '%s' berhasil dihapus.\n", judul);
            return;
        }
        temp = temp->next;
    }

    printf("Buku '%s' tidak ditemukan.\n", judul);
}

// Fungsi untuk menampilkan semua buku dalam daftar
void tampilkanBuku(Buku* head) {
    if (head == NULL) {
        printf("Daftar kosong.\n");
        return;
    }

    printf("Daftar buku:\n");
    Buku* temp = head;
    while (temp != NULL) {
        printf("Judul: %s\n", temp->judul);
        printf("Pengarang: %s\n", temp->pengarang);
        printf("Tahun: %d\n", temp->tahun);
        printf("--------------------\n");
        temp = temp->next;
    }
}

int main() {
    system("cls");
    Buku* head = NULL;

    // Contoh penggunaan
    sisipkanBukuDiAkhir(&head, "Buku 1", "Pengarang 1", 2000);
    sisipkanBukuDiAkhir(&head, "Buku 2", "Pengarang 2", 2005);
    sisipkanBukuDiAkhir(&head, "Buku 3", "Pengarang 3", 2010);
    tampilkanBuku(head);

    hapusBukuBerdasarkanJudul(&head, "Buku 2");
    tampilkanBuku(head);

    return 0;
}