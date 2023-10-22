/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 1 PENUGASAN BAGIAN 2
 */

/*
Buatlah program untuk menghitung luas dan keliling persegi panjang,
dengan ketentuan sebagai berikut:
• Data panjang dan lebar persegi panjang diinput oleh pengguna.
• Hitung luas dan keliling ditulis pada fungsi-fungsi tersendiri yang
kemudian dipanggil pada fungsi main().
• Luas dan keliling bangun persegi panjang ditampilkan sebagai
keluaran.
*/

#include <stdio.h>

int LuasPP(int Panjang, int Lebar)
{
    int Luas = Panjang*Lebar;
    return Luas;
}

int KelilingPP(int Panjang, int Lebar)
{
    int Keliling = 2*(Panjang+Lebar);
    return Keliling;
}

int main()
{
    int Panjang, Lebar;
    puts("PROGRAM MENGHITUNG LUAS DAN KELILING PERSEGI PANJANG");
    puts("====================================================");
    printf("Masukan Panjang : ");
    scanf("%i", &Panjang);
    printf("Masukan Lebar   : ");
    scanf("%i", &Lebar);
    puts("====================================================");
    printf("Luas Persegi Panjang     = %i\n", LuasPP(Panjang, Lebar));
    printf("Keliling Persegi Panjang = %i\n", KelilingPP(Panjang, Lebar)); 
    return 0;
}