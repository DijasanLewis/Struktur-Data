/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 3 PENUGASAN BAGIAN 2
    Buatlah contoh program sederhana yang memuat sebuah structure dengan
    elemen pointer di dalamnya.
*/

#include <stdio.h>

// Mendefinisikan struktur dengan elemen pointer
struct Mahasiswa {
    char *nama;
    int *umur;
};

int main() {
    struct Mahasiswa mhs;
    
    char namaMahasiswa[50];
    int umurMahasiswa;
    mhs.nama = namaMahasiswa; //memasukkan alamat bertipe string ke pointer
    mhs.umur = &umurMahasiswa; //memasukkan alamat variabel bertipe int ke pointer

    printf("Masukkan nama mahasiswa: ");
    scanf(" %[^\n]s", mhs.nama);
    printf("Masukkan umur mahasiswa: ");
    scanf("%d", mhs.umur);

    printf("\nData Mahasiswa:\n");
    printf("Nama    : %s\n", mhs.nama);
    printf("Umur    : %d tahun\n", *(mhs.umur));

    return 0;
}
