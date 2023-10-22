/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 3 PENUGASAN BAGIAN 1
    Buatlah contoh program sederhana yang memuat elemen array di dalam
    structure DAN sekaligus memuat structure di dalam array
 */

#include <stdio.h>

// Mendefinisikan struktur yang berisi elemen array
struct Mahasiswa {
    char nama[50];
    int umur;
    float nilai[4]; //Nilai Tugas, UTS, UAS, dan Nilai Akhir
};

int main() {
    puts("======== PROGRAM DATA MAHASISWA ========");
    puts("");
    
    // Mendefinisikan struktur dalam array
    int Jumlah;
    printf("Masukan jumlah mahasiswa: ");
    scanf("%d", &Jumlah);
    struct Mahasiswa daftarMahasiswa[Jumlah];
    puts("");
    
    // INPUT
    for (int i = 0; i < Jumlah; i++) {
        printf("Mahasiswa ke-%d:\n", i + 1);
        printf("Nama: ");
        scanf(" %[^\n]s", daftarMahasiswa[i].nama);
        printf("Umur: ");
        scanf("%d", &daftarMahasiswa[i].umur);
        printf("Nilai Tugas: ");
        scanf("%f", &daftarMahasiswa[i].nilai[0]);
        printf("Nilai UTS: ");
        scanf("%f", &daftarMahasiswa[i].nilai[1]);
        printf("Nilai UAS: ");
        scanf("%f", &daftarMahasiswa[i].nilai[2]);
        puts("");
        daftarMahasiswa[i].nilai[3] = 0.2*daftarMahasiswa[i].nilai[0] + 0.3*daftarMahasiswa[i].nilai[1] + 0.5*daftarMahasiswa[i].nilai[2];
    }

    puts("========================================");
    puts("");

    // OUTPUT
    printf("Data Mahasiswa:\n");
    for (int i = 0; i < Jumlah; i++) {
        printf("Mahasiswa ke-%d\n", i + 1);
        printf("Nama    : %s\n", daftarMahasiswa[i].nama);
        printf("Umur    : %d\n", daftarMahasiswa[i].umur);
        printf("Nilai Tugas : %.2lf\n", daftarMahasiswa[i].nilai[0]);
        printf("Nilai UTS   : %.2lf\n", daftarMahasiswa[i].nilai[1]);
        printf("Nilai UAS   : %.2lf\n", daftarMahasiswa[i].nilai[2]);
        printf("Nilai Akhir : %.2lf\n", daftarMahasiswa[i].nilai[3]);
        puts("");
    }

    return 0;
}
