#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct Node {
    int data;
    struct Node* berikutnya;
};

int apakahPrima(int num) {
    if (num <= 1) return 0; // Bukan prima jika kurang dari atau sama dengan 1
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0; // Bukan prima jika bisa dibagi dengan angka selain 1 dan dirinya sendiri
    }
    return 1; // Bilangan prima
}

struct Node* buatNode(int data) {
    struct Node* nodeBaru = (struct Node*)malloc(sizeof(struct Node));
    if (nodeBaru == NULL) {
        printf("Kesalahan alokasi memori!\n");
        exit(1);
    }
    nodeBaru->data = data;
    nodeBaru->berikutnya = NULL;
    return nodeBaru;
}

void tampilkanPrima(int n, int m) {
    struct Node* head = NULL;
    struct Node* temp = NULL;

    int hitung = 0;
    int num = 2;

    while (hitung < n) {
        if (apakahPrima(num)) {
            struct Node* nodeBaru = buatNode(num);
            if (head == NULL) {
                head = nodeBaru;
                temp = head;
            } else {
                temp->berikutnya = nodeBaru;
                temp = temp->berikutnya;
            }
            hitung++;
        }
        num++;
    }

    // Menampilkan bilangan prima menggunakan linked list
    temp = head;
    printf("Bilangan prima pertama %d adalah:\n", n);
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->berikutnya;
    }
    printf("\n");

    // Menggunakan realloc untuk mengubah ukuran linked list berdasarkan input m dari user
    head = (struct Node*)realloc(head, m * sizeof(struct Node));
    if (head == NULL) {
        printf("Kesalahan dalam mengalokasikan memori kembali!\n");
        exit(1);
    }

    // Membebaskan memori yang dialokasikan untuk linked list
    temp = head;
    while (temp != NULL) {
        struct Node* nodeBerikutnya = temp->berikutnya;
        free(temp);
        temp = nodeBerikutnya;
    }
}

int main() {
    system("cls");
    int n, m;

    printf("Masukkan jumlah bilangan prima yang ingin ditampilkan: ");
    scanf("%d", &n);
    printf("Masukkan ukuran memori baru (m) yang ingin dialokasikan: ");
    scanf("%d", &m);

    tampilkanPrima(n, m);

    return 0;
}