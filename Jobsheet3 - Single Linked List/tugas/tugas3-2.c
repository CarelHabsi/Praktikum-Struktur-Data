#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int apakahPrima(int num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void tampilkanPrima(int n, int m) {
    int* bilanganPrima = (int*)malloc(n * sizeof(int));
    if (bilanganPrima == NULL) {
        printf("Kesalahan alokasi memori!\n");
        exit(1);
    }

    int hitung = 0;
    int num = 2;
    while (hitung < n) {
        if (apakahPrima(num)) {
            bilanganPrima[hitung] = num;
            hitung++;
        }
        num++;
    }

    printf("Bilangan prima pertama %d adalah:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", bilanganPrima[i]);
    }
    printf("\n");

    // Menggunakan realloc untuk mengubah ukuran array berdasarkan input m dari user
    bilanganPrima = (int*)realloc(bilanganPrima, m * sizeof(int));
    if (bilanganPrima == NULL) {
        printf("Kesalahan dalam mengalokasikan memori kembali!\n");
        exit(1);
    }

    printf("Ukuran memori baru (m) yang dialokasikan: %d\n", m);
    printf("Bilangan prima pertama %d setelah penggunaan realloc adalah:\n", m);
    for (int i = 0; i < m; i++) {
        printf("%d ", bilanganPrima[i]);
    }
    printf("\n");

    free(bilanganPrima); // Membebaskan memori yang dialokasikan
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