#include <stdio.h>
#include <windows.h>

int main(){
    system("cls");
    int usia1 = 50;
    int usia2 = 18;

    //Menciptakan sebuah pointer
    int *ptr;
    //Menugaskan pointer tersebut kepada usia1
    ptr = &usia1; //& adalah operator alamat

    printf("\nUsia saya (usia1): %d", usia1); //menampilkan nilai 50
    printf("\nUsia saya (*ptr): %d", *ptr); //menampilkan nilai 50

    //*ptr merupakan nilai yang disimpan ptr, yaitu 50;
    printf("\n(&usia1) %x (ptr) %x", &usia1, ptr);

    //Menugaskan pointer tersebut kepada usia2
    ptr = &usia2;
    printf("\nUsia Anda (*ptr): %d", *ptr); //menampilkan nilai 18
    //*ptr merupakan nilai yang disimpan ptr, yaitu 18;

    printf("\n(&usia2) %x (ptr) %x", &usia2, ptr);
    //ptr adalah alamat dari usia2 jadi juga merupakan &usia2. Keduanya sama

    //Menampilkan alamat dari ptr. Anda tidak memerlukan alamat ini
    printf("\n(&ptr) %x", &ptr);

    getchar();
}