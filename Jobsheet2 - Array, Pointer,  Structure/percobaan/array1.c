#include <stdio.h>

int main(){
    int rr, nil[3];

    nil[0] = 80;
    nil[1] = 85;
    nil[2] = 90;

    rr = (nil[0] + nil[1] + nil[2]) / 3;
    printf("Nilai rata-rata dari 3 nilai adalah = %d", rr);

    return 0;
}