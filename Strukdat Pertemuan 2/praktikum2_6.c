#include <stdio.h>

int main(void){
    int number[10];
    int count = 10;
    long sum = 0L;
    float average = 0.0f;
    printf("\n Masukkanlah 10 Angka:\n");
    for(int i = 0; i < count; i++){
        printf("%2d> ",i+1);
        scanf("%d", &number[i]); /* Membaca sebuah angka */
        sum += number[i]; /* Jumlahkan setiap elemen */
    }
    average = (float)sum/count; /* Hitung Rata-rata*/
    printf("\n Rata-rata dari sepuluh Angka yang dimasukkan: %f\n", average);

    return 0;
}