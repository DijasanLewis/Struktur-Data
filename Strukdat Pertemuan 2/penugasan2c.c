/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 2 PENUGASAN BAGIAN 3
 */

#include <stdio.h>
#define Baris 3
#define Kolom 4

int main(){
    puts("PROGRAM MATRIKS 3x4");
    puts("===================\n");

    int MatriksA[Baris][Kolom];
    for(int i = 0;i<Baris;i++){
        for(int j = 0;j<Kolom;j++){
            printf("Masukan Elemen [%i,%i] = ", i+1, j+1);
            scanf("%i", &MatriksA[i][j]);
        }
    }
    puts("\n===================");
    puts("MATRIKS A");

    for(int i = 0;i<Baris;i++){
        for(int j = 0;j<Kolom;j++){
            printf("%i ", MatriksA[i][j]);
        }
        printf("\n");
    }
    return 0;
}