#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_MHS 72

typedef struct {
    char NIM[15];
    char Nama[50];
    char tanggal_lahir[10];
    float ipk;
} Mahasiswa;

int main() {
    system("cls");
    int n, i;

    printf("Jumlah maksimal mahasiswa: ");
    scanf("%d", &n);
    getchar(); // Untuk menangkap newline yang tertinggal dari scanf sebelumnya

    Mahasiswa mhs[MAX_MHS];

    for (i = 0; i < n; i++) {
        printf("\n---------------------------------------\n");

        printf("Masukkan NIM mahasiswa ke-%d: ", i+1);
        scanf("%s", mhs[i].NIM);
        getchar(); // Untuk menangkap newline yang tertinggal dari scanf

        printf("Masukkan nama mahasiswa ke-%d: ", i+1);
        fgets(mhs[i].Nama, sizeof(mhs[i].Nama), stdin);
        mhs[i].Nama[strcspn(mhs[i].Nama, "\n")] = 0; // Menghapus newline di akhir input

        printf("Masukkan tanggal lahir mahasiswa ke-%d: ", i+1);
        scanf("%s", mhs[i].tanggal_lahir);
        getchar(); // Untuk menangkap newline yang tertinggal dari scanf

        printf("Masukkan IPK mahasiswa ke-%d: ", i+1);
        scanf("%f", &mhs[i].ipk);
        getchar(); // Untuk menangkap newline yang tertinggal dari scanf
    }

    printf("\n---------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("Mahasiswa ke - %d\n", i+1);
        printf("NIM : %s\n", mhs[i].NIM);
        printf("Nama : %s\n", mhs[i].Nama);
        printf("Tanggal Lahir : %s\n", mhs[i].tanggal_lahir);
        printf("IPK : %.2f\n", mhs[i].ipk);
        printf("\n");
    }

    return 0;
}