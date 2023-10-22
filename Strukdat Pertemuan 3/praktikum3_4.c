#include<stdio.h>
struct data_tanggal
{
    int tahun;
    int bulan;
    int tanggal;
} ultah;

int main()
{
    //menginisialisasi elemen-elemen struct ultah
    ultah.tanggal = 29; //ganti dengan tanggal lahir Anda
    ultah.bulan = 9; //ganti dengan bulan lahir Anda
    ultah.tahun = 2004; //ganti dengan tahun lahir Anda
    //mengakses elemen-elemen struct ultah
    printf ("tanggal = %d, bulan = %d, tahun = %d",ultah.tanggal, ultah.bulan, ultah.tahun);
    return 0;
}
