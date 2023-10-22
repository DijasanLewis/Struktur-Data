/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 1 PENUGASAN BAGIAN 1
 */

/*
Buatlah sebuah program yang dapat yang dapat mengolah data mahasiswa
dengan ketentuan:
● Pengguna menginputkan NIM, Nama, Nilai Kuis, Nilai UTS, dan Nilai
UAS.
● Hasil atau output yang diinginkan: NIM, Nama, Nilai Kuis, Nilai UTS,
Nilai UAS, dan Nilai Akhir.
● Nilai akhir = 20% dari nilai kuis + 30% dari nilai UTS + 50% dari nilai
UAS.
*/

#include <stdio.h>

int main()
{
    char NIM[11], Nama[20];
    float NilaiKuis, NilaiUTS, NilaiUAS, NilaiAkhir;
    puts("============PROGRAM DATA MAHASISWA============");
    puts("==============================================");
    printf("Masukan NIM         : ");
    fgets(NIM, sizeof(NIM), stdin);
    printf("Masukan Nama        : ");
    fgets(Nama, sizeof(Nama), stdin);
    printf("Masukan Nilai Kuis  : ");
    scanf(" %f", &NilaiKuis);
    printf("Masukan Nilai UTS   : ");
    scanf(" %f", &NilaiUTS);
    printf("Masukan Nilai UAS   : ");
    scanf(" %f", &NilaiUAS);
    puts("==============================================");
    
    NilaiAkhir = 0.2*NilaiKuis + 0.3*NilaiUTS + 0.5*NilaiUAS;
    printf("NIM         : %s", NIM);
    printf("Nama        : %s\n", Nama);
    printf("Nilai Kuis  : %.2f\n", NilaiKuis);
    printf("Nilai UTS   : %.2f\n", NilaiUTS);
    printf("Nilai UAS   : %.2f\n", NilaiUAS);
    printf("NIlai Akhir : %.2f\n", NilaiAkhir);
    
    return 0;
}
