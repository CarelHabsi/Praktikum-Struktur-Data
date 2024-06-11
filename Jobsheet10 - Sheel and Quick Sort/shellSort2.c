#include <stdio.h>
#include <windows.h>

int main(){
    system("cls");
    int L[20], temp, i, j, n = 6, m;
    printf("pengurutan berdasarkan  Shell sort \nMasukkan %d elements: \n", n);

    for (i = 0; i < n; i++){
        scanf("%d", &L[i]);
    }
    printf("Data sebelum disorting: \n");
    for (i = 0; i < n; i++){
        printf("%d ", L[i]);
    }
    for(m = n/2; m > 0; m = m/2){
        /* 6 7 2 1 => 2 7 6 1 6 7 // 1 2 6 7, 1 2 6 7, 1 2 6 7 */
        for(j = m; j < n; j++){
            for(i = j - m; i >= 0; i = i - m){
                if(L[i + m] >= L[i]){
                    break;
                } 

                else {
                    temp = L[i];
                    L[i] = L[i + m];
                    L[i + m] = temp;
                }
            }
        }
}

    printf("\nData setelah disorting: \n");
    for (i = 0; i < n; i++){
        printf("%d ", L[i]);
    }
    return 0;
}