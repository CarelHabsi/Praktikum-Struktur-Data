#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct Tugas {
    char nama[100];
    int hari;
    int bulan;
    int tahun;
} Tugas;

typedef struct Node {
    Tugas tugas;
    struct Node *next;
} Node;

Node *head = NULL;

// Fungsi untuk menambah tugas dengan singly linked list
void tambahTugas(char *nama, int hari, int bulan, int tahun) {
    Node *nodeBaru = (Node *)malloc(sizeof(Node));
    strcpy(nodeBaru->tugas.nama, nama);
    nodeBaru->tugas.hari = hari;
    nodeBaru->tugas.bulan = bulan;
    nodeBaru->tugas.tahun = tahun;
    nodeBaru->next = NULL;
    
    if (head == NULL) {
        head = nodeBaru;
    } else {
        Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nodeBaru;
    }
}

// Fungsi untuk mengedit tugas
void editTugas(char *nama, char *namaBaru, int hariBaru, int bulanBaru, int tahunBaru) {
    Node *node = head;
    while (node != NULL) {
        if (strcmp(node->tugas.nama, nama) == 0) {
            strcpy(node->tugas.nama, namaBaru);
            node->tugas.hari = hariBaru;
            node->tugas.bulan = bulanBaru;
            node->tugas.tahun = tahunBaru;
            return;
        }
        node = node->next;
    }
    printf("Tugas tidak ditemukan.\n");
}

// Fungsi untuk menghapus tugas
void hapusTugas(char *nama) {
    Node *node = head, *prev = NULL;
    while (node != NULL && strcmp(node->tugas.nama, nama) != 0) {
        prev = node;
        node = node->next;
    }
    if (node == NULL) {
        printf("Tugas tidak ditemukan.\n");
        return;
    }
    if (prev == NULL) {
        head = node->next;
    } else {
        prev->next = node->next;
    }
    free(node);
}

// Fungsi untuk menampilkan semua tugas
void tampilkanTugas() {
    Node *node = head;
    int nomor = 1;
    while (node != NULL) {
        printf("%d. Nama: %s, Tenggat: %02d-%02d-%04d\n", nomor++, node->tugas.nama, node->tugas.hari, node->tugas.bulan, node->tugas.tahun);
        node = node->next;
    }
}

// Fungsi untuk membandingkan dua tugas berdasarkan tenggat
int compareTugas(Tugas t1, Tugas t2) {
    if (t1.tahun != t2.tahun)
        return t1.tahun - t2.tahun;
    if (t1.bulan != t2.bulan)
        return t1.bulan - t2.bulan;
    return t1.hari - t2.hari;
}

// Fungsi untuk menggabungkan dua bagian daftar/list yang diurutkan ascending
Node* merge(Node* kiri, Node* kanan) {
    Node* hasil = NULL;

    if (!kiri) return kanan;
    if (!kanan) return kiri;

    if (compareTugas(kiri->tugas, kanan->tugas) <= 0) {
        hasil = kiri;
        hasil->next = merge(kiri->next, kanan);
    } else {
        hasil = kanan;
        hasil->next = merge(kiri, kanan->next);
    }

    return hasil;
}

// Fungsi untuk menggabungkan dua bagian daftar/list yang diurutkan descending
Node* mergeDesc(Node* kiri, Node* kanan) {
    Node* hasil = NULL;

    if (!kiri) return kanan;
    if (!kanan) return kiri;

    if (compareTugas(kiri->tugas, kanan->tugas) >= 0) {
        hasil = kiri;
        hasil->next = mergeDesc(kiri->next, kanan);
    } else {
        hasil = kanan;
        hasil->next = mergeDesc(kiri, kanan->next);
    }

    return hasil;
}

// Fungsi untuk membagi daftar/list menjadi dua bagian
void bagi(Node* sumber, Node** referensiDepan, Node** referensiBelakang) {
    Node* cepat;
    Node* lambat;
    if (sumber == NULL || sumber->next == NULL) {
        *referensiDepan = sumber;
        *referensiBelakang = NULL;
    } else {
        lambat = sumber;
        cepat = sumber->next;
        while (cepat != NULL) {
            cepat = cepat->next;
            if (cepat != NULL) {
                lambat = lambat->next;
                cepat = cepat->next;
            }
        }
        *referensiDepan = sumber;
        *referensiBelakang = lambat->next;
        lambat->next = NULL;
    }
}

// Fungsi Merge Sort untuk mengurutkan tugas
void mergeSort(Node** headRef, int ascending) {
    Node* head = *headRef;
    Node* kiri;
    Node* kanan;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    bagi(head, &kiri, &kanan);

    mergeSort(&kiri, ascending);
    mergeSort(&kanan, ascending);

    if (ascending) {
        *headRef = merge(kiri, kanan);
    } else {
        *headRef = mergeDesc(kiri, kanan);
    }
}

Node* linearSearch(Node *headRef, char *nama) {
    Node *node = headRef;
    while (node != NULL) {
        if (strcmp(node->tugas.nama, nama) == 0) {
            return node;
        }
        node = node->next;
    }
    return NULL;
}


int validasiTanggal(char *tenggat, int *hari, int *bulan, int *tahun) {
    return sscanf(tenggat, "%d-%d-%d", hari, bulan, tahun) == 3 &&
           *hari >= 1 && *hari <= 31 &&
           *bulan >= 1 && *bulan <= 12 &&
           *tahun >= 1900 && *tahun <= 2100;
}

void menu() {
    printf("Manajemen Pengumpulan Tugas\n");
    printf("1. Tambah Tugas\n");
    printf("2. Edit Tugas\n");
    printf("3. Hapus Tugas\n");
    printf("4. Tampilkan Semua Tugas\n");
    printf("5. Urutkan Tugas Berdasarkan Tenggat Pengumpulan (Naik)\n");
    printf("6. Urutkan Tugas Berdasarkan Tenggat Pengumpulan (Turun)\n");
    printf("7. Cari Tugas Berdasarkan Nama\n");
    printf("8. Keluar\n");
}

void ambilInput(char *prompt, char *input, int panjang) {
    printf("%s", prompt);
    fgets(input, panjang, stdin);
    input[strcspn(input, "\n")] = 0;  // menghapus karakter newline
}

int main() {
    system("cls");
    printf("Nama : Carel Habsian Osagi\n");
    printf("NIM  : 23343061\n");
    printf("Prodi: S1 Informatika (NK)\n\n"); 
    int pilihan;
    char nama[100], tenggat[20], namaBaru[100], tenggatBaru[20];
    int hari, bulan, tahun;
    int hariBaru, bulanBaru, tahunBaru;

    while (1) {
        menu();
        printf("Pilih opsi: ");
        scanf("%d", &pilihan);
        getchar();  // membersihkan buffer setelah input pilihan

        switch (pilihan) {
             case 1:
                while (1) {
                    ambilInput("Masukkan nama tugas (atau -1 untuk berhenti): ", nama, sizeof(nama));
                    if (strcmp(nama, "-1") == 0) {
                        break;
                    }
                    ambilInput("Masukkan tenggat (dd-mm-yyyy): ", tenggat, sizeof(tenggat));
                    if (!validasiTanggal(tenggat, &hari, &bulan, &tahun)) {
                        printf("Tanggal tidak valid. Harap gunakan format dd-mm-yyyy.\n");
                        continue;
                    }
                    tambahTugas(nama, hari, bulan, tahun);
                }
                break;
            case 2:
                ambilInput("Masukkan nama tugas yang ingin diedit: ", nama, sizeof(nama));
                ambilInput("Masukkan nama tugas baru: ", namaBaru, sizeof(namaBaru));
                ambilInput("Masukkan tenggat baru (dd-mm-yyyy): ", tenggatBaru, sizeof(tenggatBaru));
                if (!validasiTanggal(tenggatBaru, &hariBaru, &bulanBaru, &tahunBaru)) {
                    printf("Tanggal tidak valid. Harap gunakan format dd-mm-yyyy.\n");
                    break;
                }
                editTugas(nama, namaBaru, hariBaru, bulanBaru, tahunBaru);
                break;
            case 3:
                ambilInput("Masukkan nama tugas yang ingin dihapus: ", nama, sizeof(nama));
                hapusTugas(nama);
                break;
            case 4:
                tampilkanTugas();
                break;
            case 5:
                mergeSort(&head, 1);
                printf("Tugas telah diurutkan secara ascending berdasarkan tenggat pengumpulan.\n");
                break;
            case 6:
                mergeSort(&head, 0);
                printf("Tugas telah diurutkan secara descending berdasarkan tenggat pengumpulan.\n");
                break;
            case 7:
                ambilInput("Masukkan nama tugas yang ingin dicari: ", nama, sizeof(nama));
                Node *ditemukan = linearSearch(head, nama);
                if (ditemukan != NULL) {
                    printf("Tugas ditemukan: Nama: %s, Tenggat: %02d-%02d-%04d\n", ditemukan->tugas.nama, ditemukan->tugas.hari, ditemukan->tugas.bulan, ditemukan->tugas.tahun);
                } else {
                    printf("Tugas tidak ditemukan.\n");
                }
                break;
            case 8:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Pilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    }

    return 0;
}