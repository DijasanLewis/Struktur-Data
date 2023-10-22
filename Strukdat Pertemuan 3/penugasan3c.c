/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 3 PENUGASAN BAGIAN 3
    Buatlah contoh program sederhana yang memuat sebuah pointer yang menunjuk
    sebuah structure.
*/

#include <stdio.h>

struct Mahasiswa {
    char nama[50];
    int umur;
};

int main() {
    // Mendefinisikan variabel struktur dan pointer yang menunjuk ke struktur
    struct Mahasiswa mahasiswa;
    struct Mahasiswa *pointerMahasiswa;

    // memasukkan alamat struktur ke pointer
    pointerMahasiswa = &mahasiswa;

    // Mengisi data ke dalam struktur melalui pointer
    puts("======== DATA MAHASISWA ========");
    printf("Masukkan nama mahasiswa: ");
    scanf(" %[^\n]s", pointerMahasiswa->nama);
    printf("Masukkan umur mahasiswa: ");
    scanf("%d", &pointerMahasiswa->umur);

    // Menampilkan data dari struktur melalui pointer
    printf("\nData Mahasiswa:\n");
    printf("Nama: %s\n", pointerMahasiswa->nama);
    printf("Umur: %d tahun\n", pointerMahasiswa->umur);

    return 0;
}
