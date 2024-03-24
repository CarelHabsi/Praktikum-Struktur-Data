#include <stdio.h>

int main(){
    int n, bil[100];

    printf("Masukkan banyaknya bilangan: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        printf("Masukkan bilangan ke-%d: ", i+1);
        scanf("%d", &bil[i]);
    }

    for(int i=0; i<n; i++){
        printf("Bilangan ke-%d = %d\n", i+1, bil[i]);
    }

    getchar();
    return 0;
}