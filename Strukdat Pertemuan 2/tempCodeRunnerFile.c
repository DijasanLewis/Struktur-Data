#include <stdio.h>
#define Baris 3
#define Kolom 4

int main(){
    puts("PROGRAM MATRIKS 3x4");
    puts("===================");
    
    int MatriksA[Baris][Kolom];
    for(int i = 0;i<Baris;i++){
        for(int j = 0;j<Kolom;j++){
            printf("Elemen [%i,%i] = ", i, j);
            scanf("%i", &MatriksA[i][j]);
        }
    }
    puts("===================");
    for(int i = 0;i<Baris;i++){
        for(int j = 0;j<Kolom;j++){
            printf("%i ", MatriksA[i][j]);
        }
        printf("\n");
    }
    return 0;
}