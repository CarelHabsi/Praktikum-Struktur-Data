#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Buku {
    char judul[100];
    char pengarang[50];
    int tahun;
    struct Buku* next;
};

void tambahBuku(struct Buku** kepala, char judul[], char pengarang[], int tahun) {
    struct Buku* bukuBaru = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->pengarang, pengarang);
    bukuBaru->tahun = tahun;
    bukuBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = bukuBaru;
    } else {
        struct Buku* current = *kepala;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = bukuBaru;
    }

    printf("Buku berhasil didaftarkan.\n");
}

void tambahBukuKeAwal(struct Buku** kepala, char judul[], char pengarang[], int tahun) {
    struct Buku* bukuBaru = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->pengarang, pengarang);
    bukuBaru->tahun = tahun;
    bukuBaru->next = *kepala;
    *kepala = bukuBaru;
    printf("Buku berhasil ditambahkan pada awal perpustakaan.\n");
}

void tambahBukuKeAkhir(struct Buku** kepala, char judul[], char pengarang[], int tahun) {
    struct Buku* bukuBaru = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->pengarang, pengarang);
    bukuBaru->tahun = tahun;
    bukuBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = bukuBaru;
    } else {
        struct Buku* current = *kepala;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = bukuBaru;
    }

    printf("Buku berhasil ditambahkan pada akhir perpustakaan.\n");
}

void tambahBukuPadaPosisi(struct Buku** kepala, char judul[], char pengarang[], int tahun, int posisi) {
    struct Buku* bukuBaru = (struct Buku*)malloc(sizeof(struct Buku));
    strcpy(bukuBaru->judul, judul);
    strcpy(bukuBaru->pengarang, pengarang);
    bukuBaru->tahun = tahun;
    bukuBaru->next = NULL;

    if (posisi == 0) {
        bukuBaru->next = *kepala;
        *kepala = bukuBaru;
        printf("Buku berhasil ditambahkan pada posisi 0 dalam perpustakaan.\n");
        return;
    }

    struct Buku* current = *kepala;
    int count = 0;
    while (current != NULL && count < posisi - 1) {
        current = current->next;
        count++;
    }

    if (current == NULL) {
        printf("Posisi tidak valid.\n");
        free(bukuBaru);
        return;
    }

    bukuBaru->next = current->next;
    current->next = bukuBaru;
    printf("Buku berhasil ditambahkan pada posisi %d dalam perpustakaan.\n", posisi);
}

void hapusBuku(struct Buku** kepala, char judul[]) {
    if (*kepala == NULL) {
        printf("Perpustakaan kosong.\n");
        return;
    }

    struct Buku* current = *kepala;
    struct Buku* prevNode = NULL;

    while (current != NULL) {
        if (strcmp(current->judul, judul) == 0) {
            if (prevNode == NULL) {
                *kepala = current->next;
            } else {
                prevNode->next = current->next;
            }

            printf("Buku dengan judul '%s' berhasil dihapus.\n", judul);
            free(current);
            return;
        }
        prevNode = current;
        current = current->next;
    }

    printf("Buku dengan judul '%s' tidak ditemukan.\n", judul);
}

void tampilkanPerpustakaan(struct Buku* kepala) {
    if (kepala == NULL) {
        printf("Perpustakaan kosong.\n");
    } else {
        struct Buku* current = kepala;
        printf("Daftar Buku dalam Perpustakaan:\n");
        while (current != NULL) {
            printf("Judul: %s\n", current->judul);
            printf("Pengarang: %s\n", current->pengarang);
            printf("Tahun Terbit: %d\n", current->tahun);
            printf("--------------------\n");
            current = current->next;
        }
    }
}

void bebaskanPerpustakaan(struct Buku** kepala) {
    struct Buku* current = *kepala;
    while (current != NULL) {
        struct Buku* temp = current;
        current = current->next;
        free(temp);
    }
    *kepala = NULL;
    printf("Semua buku berhasil dihapus dari perpustakaan.\n");
}

int main() {
    system("cls");
    struct Buku* kepala = NULL;
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Tambah buku ke perpustakaan\n");
        printf("2. Tambah buku ke awal perpustakaan\n");
        printf("3. Tambah buku ke akhir perpustakaan\n");
        printf("4. Tambah buku pada posisi tertentu dalam perpustakaan\n");
        printf("5. Hapus buku dari perpustakaan\n");
        printf("6. Tampilkan buku dalam perpustakaan\n");
        printf("7. Hapus semua buku dari perpustakaan\n");
        printf("8. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                char judul[100];
                char pengarang[50];
                int tahun;
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan nama pengarang: ");
                scanf("%s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                tambahBuku(&kepala, judul, pengarang, tahun);
                break;
            }
            case 2: {
                char judul[100];
                char pengarang[50];
                int tahun;
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan nama pengarang: ");
                scanf("%s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                tambahBukuKeAwal(&kepala, judul, pengarang, tahun);
                break;
            }
            case 3: {
                char judul[100];
                char pengarang[50];
                int tahun;
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan nama pengarang: ");
                scanf("%s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                tambahBukuKeAkhir(&kepala, judul, pengarang, tahun);
                break;
            }
            case 4: {
                char judul[100];
                char pengarang[50];
                int tahun, posisi;
                printf("Masukkan judul buku: ");
                scanf("%s", judul);
                printf("Masukkan nama pengarang: ");
                scanf("%s", pengarang);
                printf("Masukkan tahun terbit: ");
                scanf("%d", &tahun);
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                tambahBukuPadaPosisi(&kepala, judul, pengarang, tahun, posisi);
                break;
            }
            case 5: {
                char judul[100];
                printf("Masukkan judul buku yang ingin dihapus: ");
                scanf("%s", judul);
                hapusBuku(&kepala, judul);
                break;
            }
            case 6: {
                tampilkanPerpustakaan(kepala);
                break;
            }
            case 7: {
                bebaskanPerpustakaan(&kepala);
                break;
            }
            case 8: {
                bebaskanPerpustakaan(&kepala);
                return 0;
            }
            default: {
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
            }
        }
    } while (1);

    return 0;
}
