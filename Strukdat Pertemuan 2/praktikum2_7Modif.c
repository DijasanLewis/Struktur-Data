/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 2 MODIFIKASI PRAKTIKUM2_7
 */

#include <stdio.h>

int main(){
    int Baris, Kolom, i, j;
    puts("PROGRAM PENJUMLAHAN MATRIKS");
    puts("===========================\n");
    printf("Masukan Jumlah Baris : ");
    scanf("%d", &Baris);
    printf("Masukan Jumlah Kolom : ");
    scanf("%d", &Kolom);

    int Matriks_A[Baris][Kolom], Matriks_B[Baris][Kolom], Matriks_C[Baris][Kolom];
    
    puts("\n========================");
    puts("Masukan Elemen Matriks A");
    for(i=0;i<Baris;i++){
        for(j=0;j<Kolom;j++){
            printf("Matriks A[%d,%d] = ", i+1, j+1);
            scanf("%d", &Matriks_A[i][j]);
        }
    }
    puts("\n========================");
    puts("Masukan Elemen Matriks B");
    for(i=0;i<Baris;i++){
        for(j=0;j<Kolom;j++){
            printf("Matriks B[%d,%d] = ", i+1, j+1);
            scanf("%d", &Matriks_B[i][j]);
        }
    }

    puts("\n========================");
    puts("MATRIKS A");
    for(i=0;i<Baris;i++){
        for(j=0;j<Kolom;j++){
            printf("%3d ", Matriks_A[i][j]);
        }
        puts("");
    }

    puts("MATRIKS B");
    for(i=0;i<Baris;i++){
        for(j=0;j<Kolom;j++){
            printf("%3d ", Matriks_B[i][j]);
        }
        puts("");
    }
    printf("Matriks_C adalah : \n");
    for(int i = 0; i < Baris; i++){
        for(int j = 0; j < Kolom; j++){
            Matriks_C[i][j] = Matriks_A[i][j] + Matriks_B[i][j];
        }
        printf("%3d %3d %3d\n", Matriks_C[i][0], Matriks_C[i][1], Matriks_C[i][2]);
    }
    return 0; 
}
