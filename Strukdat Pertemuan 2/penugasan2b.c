/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 2 PENUGASAN BAGIAN 2
 */

/* Aturan Scope pada Bahasa C */
#include <stdio.h>

int main()
{
    {
        int x = 10, y = 20; //x dan y variabel global
        {
            printf("x = %d, y = %d\n", x, y);
            {
                int y= 40; //y di sini adalah variabel y lokal
                x++; //x yang diubah adalah x global
                y++; //y yang diubah adalah y lokal
                printf("x = %d, y = %d\n", x, y);
                //yang diprint adalah x global dan y lokal
            } 
            /*dari sini, perubahan y lokal tidak berlaku lagi,
            sementara perubahan x global masih berlaku*/
            printf("x = %d, y = %d\n", x, y); 
            /*yang diprint adalah x global yang sudah diubah
            dan y global yang belum diubah*/            
        }
    }
    return 0;
}