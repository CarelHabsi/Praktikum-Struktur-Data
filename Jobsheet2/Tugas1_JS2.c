#include <stdio.h>
#define MAX_MHS 72

typedef struct {
    char NIM[15];
    char Nama[50];
    char tanggal_lahir[10];
    float ipk;
} Mahasiswa;

int main() {
    int n;

    printf("Jumlah maksimal mahasiswa: ");
    scanf("%d", &n);

    Mahasiswa mhs[MAX_MHS];

    for (int i = 0; i < n; i++) {
    	printf("---------------------------------------\n");
    	
        printf("Masukkan NIM mahasiswa ke-%d: ", i+1);
        scanf("%s", mhs[i].NIM);

        printf("Masukkan nama mahasiswa ke-%d: ", i+1);
        scanf("%s", mhs[i].Nama);

        printf("Masukkan tanggal lahir mahasiswa ke-%d: ", i+1);
        scanf("%s", mhs[i].tanggal_lahir);

        printf("Masukkan IPK mahasiswa ke-%d: ", i+1);
        scanf("%f", &mhs[i].ipk);  
    }

    return 0;
}