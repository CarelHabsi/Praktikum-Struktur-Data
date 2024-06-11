#include <stdio.h> 
#include <stdlib.h>
#include <windows.h>

int main() { 
    system("cls");
    int tabInt[10] = {12, 23, 29, 34, 56, 60, 67, 78, 84, 99}; 
    int i, j, k; 
    int cariData, ketemu; 

    printf("Data yang terdapat pada array : \n");
    for(i = 0; i < 10; i++) { 
        printf("%d ", tabInt[i]); 
    }
    printf("\n");

    printf("Masukkan data yang dicari = "); 
    scanf("%d", &cariData); 

    i = 0; 
    j = 9; 
    ketemu = 0; 

    while((ketemu == 0) && (i <= j)) { 
        k = (int)(i + j) / 2; 

        if(tabInt[k] == cariData) { 
            ketemu = 1; 
        } 
        else { 
            if(tabInt[k] > cariData) { 
                j = k - 1; 
            } 
            else { 
                i = k + 1; 
            } 
        } 
    } 

    if(ketemu == 1) { 
        printf("Data %d terdapat pada kumpulan data\n", cariData); 
    }
    else { 
        printf("Data %d tidak terdapat pada kumpulan data\n", cariData); 
    } 

    return 0;
}
