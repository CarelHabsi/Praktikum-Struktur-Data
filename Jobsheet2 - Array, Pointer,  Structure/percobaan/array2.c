#include <stdio.h>

int main(){
    int n[10];
    int i, j;

    for (i = 0; i < 10; i++){
        n[i] = i + 100;
    }

    for (j = 0; j < 10; j++){
        printf("Elemen ke-%d = %d\n", j+1, n[j]);
    }

    return 0;
}