#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Mobil {
    char noPlat[20];
    char merkMobil[20];
    char namaPemilik[50];
    struct Mobil* next;
};

void tambahParkiran(struct Mobil** kepala, struct Mobil** ekor, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Mobil* mobilBaru = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobilBaru->noPlat, noPlat);
    strcpy(mobilBaru->merkMobil, merkMobil);
    strcpy(mobilBaru->namaPemilik, namaPemilik);
    mobilBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = mobilBaru;
        *ekor = mobilBaru;
    } else {
        (*ekor)->next = mobilBaru;
        *ekor = mobilBaru;
    }

    printf("Mobil ditambahkan ke parkiran.\n");
}

void keluarkanParkiran(struct Mobil** kepala, struct Mobil** ekor) {
    if (*kepala == NULL) {
        printf("Parkiran kosong.\n");
    } else {
        struct Mobil* temp = *kepala;
        *kepala = (*kepala)->next;
        free(temp);
        printf("Mobil dikeluarkan dari parkiran.\n");
    }
}

void tampilkanParkiran(struct Mobil* kepala) {
    if (kepala == NULL) {
        printf("Parkiran kosong.\n");
    } else {
        struct Mobil* current = kepala;
        printf("Mobil dalam parkiran:\n");
        while (current != NULL) {
            printf("Nomor Plat: %s\n", current->noPlat);
            printf("Merk Mobil: %s\n", current->merkMobil);
            printf("Nama Pemilik: %s\n", current->namaPemilik);
            printf("--------------------\n");
            current = current->next;
        }
    }
}

void bebaskanParkiran(struct Mobil* kepala) {
    struct Mobil* current = kepala;
    while (current != NULL) {
        struct Mobil* temp = current;
        current = current->next;
        free(temp);
    }
}

void tambahMobilKeAwal(struct Mobil** kepala, struct Mobil** ekor, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Mobil* mobilBaru = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobilBaru->noPlat, noPlat);
    strcpy(mobilBaru->merkMobil, merkMobil);
    strcpy(mobilBaru->namaPemilik, namaPemilik);
    mobilBaru->next = *kepala;

    if (*kepala == NULL) {
        *kepala = mobilBaru;
        *ekor = mobilBaru;
    } else {
        *kepala = mobilBaru;
    }

    printf("Mobil ditambahkan ke awal parkiran.\n");
}

void tambahMobilKeAkhir(struct Mobil** kepala, struct Mobil** ekor, char noPlat[], char merkMobil[], char namaPemilik[]) {
    struct Mobil* mobilBaru = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobilBaru->noPlat, noPlat);
    strcpy(mobilBaru->merkMobil, merkMobil);
    strcpy(mobilBaru->namaPemilik, namaPemilik);
    mobilBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = mobilBaru;
        *ekor = mobilBaru;
    } else {
        (*ekor)->next = mobilBaru;
        *ekor = mobilBaru;
    }

    printf("Mobil ditambahkan ke akhir parkiran.\n");
}

void tambahMobilPadaPosisi(struct Mobil** kepala, struct Mobil** ekor, char noPlat[], char merkMobil[], char namaPemilik[], int posisi) {
    struct Mobil* mobilBaru = (struct Mobil*)malloc(sizeof(struct Mobil));
    strcpy(mobilBaru->noPlat, noPlat);
    strcpy(mobilBaru->merkMobil, merkMobil);
    strcpy(mobilBaru->namaPemilik, namaPemilik);
    mobilBaru->next = NULL;

    if (*kepala == NULL) {
        *kepala = mobilBaru;
        *ekor = mobilBaru;
    } else if (posisi == 0) {
        mobilBaru->next = *kepala;
        *kepala = mobilBaru;
    } else {
        struct Mobil* current = *kepala;
        int count = 0;
        while (current != NULL && count < posisi - 1) {
            current = current->next;
            count++;
        }
        if (current == NULL) {
            printf("Posisi tidak valid.\n");
            return;
        }
        mobilBaru->next = current->next;
        current->next = mobilBaru;
    }

    printf("Mobil ditambahkan pada posisi %d dalam parkiran.\n", posisi);
}

void hapusSemuaMobil(struct Mobil** kepala, struct Mobil** ekor) {
    struct Mobil* current = *kepala;
    while (current != NULL) {
        struct Mobil* temp = current;
        current = current->next;
        free(temp);
    }
    *kepala = NULL;
    *ekor = NULL;
    printf("Semua mobil dihapus dari parkiran.\n");
}

void hapusMobilDenganNoPlat(struct Mobil** kepala, struct Mobil** ekor, char noPlat[]) {
    if (*kepala == NULL) {
        printf("Parkiran kosong.\n");
        return;
    }

    struct Mobil* current = *kepala;
    struct Mobil* prevNode = NULL;

    while (current != NULL) {
        if (strcmp(current->noPlat, noPlat) == 0) {
            if (prevNode == NULL) {
                *kepala = current->next;
            } else {
                prevNode->next = current->next;
            }

            if (current->next == NULL) {
                *ekor = prevNode;
            }

            printf("Mobil dengan nomor plat %s dihapus dari parkiran.\n", noPlat);
            free(current);
            return;
        }
        prevNode = current;
        current = current->next;
    }

    printf("Mobil dengan nomor plat %s tidak ditemukan dalam parkiran.\n", noPlat);
}

int main() {
    system("cls");
    struct Mobil* kepala = NULL;
    struct Mobil* ekor = NULL;
    int pilihan;

    do {
        printf("Menu:\n");
        printf("1. Tambah mobil ke parkiran\n");
        printf("2. Keluarkan mobil dari parkiran\n");
        printf("3. Tampilkan mobil dalam parkiran\n");
        printf("4. Tambah mobil ke awal parkiran\n");
        printf("5. Tambah mobil ke akhir parkiran\n");
        printf("6. Tambah mobil pada posisi tertentu dalam parkiran\n");
        printf("7. Hapus semua mobil dari parkiran\n");
        printf("8. Hapus mobil berdasarkan nomor plat\n");
        printf("9. Keluar\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        switch (pilihan) {
            case 1: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Masukkan nomor plat: ");
                scanf("%s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf("%s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf("%s", namaPemilik);
                tambahParkiran(&kepala, &ekor, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 2: {
                keluarkanParkiran(&kepala, &ekor);
                break;
            }
            case 3: {
                tampilkanParkiran(kepala);
                break;
            }
            case 4: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Masukkan nomor plat: ");
                scanf("%s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf("%s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf("%s", namaPemilik);
                tambahMobilKeAwal(&kepala, &ekor, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 5: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                printf("Masukkan nomor plat: ");
                scanf("%s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf("%s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf("%s", namaPemilik);
                tambahMobilKeAkhir(&kepala, &ekor, noPlat, merkMobil, namaPemilik);
                break;
            }
            case 6: {
                char noPlat[20];
                char merkMobil[20];
                char namaPemilik[50];
                int posisi;
                printf("Masukkan nomor plat: ");
                scanf("%s", noPlat);
                printf("Masukkan merk mobil: ");
                scanf("%s", merkMobil);
                printf("Masukkan nama pemilik: ");
                scanf("%s", namaPemilik);
                printf("Masukkan posisi: ");
                scanf("%d", &posisi);
                tambahMobilPadaPosisi(&kepala, &ekor, noPlat, merkMobil, namaPemilik, posisi);
                break;
            }
            case 7: {
                hapusSemuaMobil(&kepala, &ekor);
                break;
            }
            case 8: {
                char noPlat[20];
                printf("Masukkan nomor plat untuk dihapus: ");
                scanf("%s", noPlat);
                hapusMobilDenganNoPlat(&kepala, &ekor, noPlat);
                break;
            }
            case 9: {
                bebaskanParkiran(kepala);
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
