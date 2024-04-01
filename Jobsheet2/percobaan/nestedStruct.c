#include <stdio.h>
#include <windows.h>

struct complex{
    int imag;
    float real;
};

struct number{
    struct complex comp;
    int integers;
};

struct level3{
    struct number num;
    char character;
};

struct level4{
    struct level3 lvl3;
    double decimal;
};

struct level5{
    struct level4 lvl4;
    long longValue;
};

int main(){
    system("cls");

    struct level5 lvl5;
    // Accessing nested struct members
    lvl5.lvl4.lvl3.num.comp.imag = 10;
    lvl5.lvl4.lvl3.num.comp.real = 3.14;
    lvl5.lvl4.lvl3.num.integers = 5;
    lvl5.lvl4.lvl3.character = 'A';
    lvl5.lvl4.decimal = 2.71828;
    lvl5.longValue = 1000000;

    printf("Nested Struct Members:\n");
    printf("Imaginary Part: %d\n", lvl5.lvl4.lvl3.num.comp.imag);
    printf("Real Part: %.2f\n", lvl5.lvl4.lvl3.num.comp.real);
    printf("Integers: %d\n", lvl5.lvl4.lvl3.num.integers);
    printf("Character: %c\n", lvl5.lvl4.lvl3.character);
    printf("Decimal: %.5f\n", lvl5.lvl4.decimal);
    printf("Long Value: %ld\n", lvl5.longValue);

    return 0;
}