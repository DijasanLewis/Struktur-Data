/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 7:
    1. Output dari program yang dibuat adalah seperti gambar di bawah.
    Perbaiki program agar yang muncul hanya yang diinputkan saja
    2. Modifikasi program agar secara otomatis antrian hanya maksimal
    berisi 5 pendaftar terbaik sesuai kriteria yang ditentukan.
    3. Modifikasi program tersebut agar menampilkan mulai dari urutan teratas.
    4. Buat yang versi arraynya

    BAGIAN 4
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi
typedef struct data{
    char nama[20];
    int alpro;
    int kalkulus;
} mahasiswa;

int front = -1, rear = -1, count = 0;
//soal 2
int maxArray = 40, maxPendaftar = 5; 

//Fungsi dequeue
void dequeue(mahasiswa mhs[maxArray]){
    front++;
    count--;
}
//Fungsi enqueue
void enqueue(mahasiswa mhs[maxArray], char n[], int alp, int kal){
    if(front == -1){
        front = 0;
    }
    rear++;
    strcpy(mhs[rear].nama, n);
    mhs[rear].alpro = alp;
    mhs[rear].kalkulus = kal;
    count++;
}

//fungsi tukar
void Tukar(mahasiswa mhs[maxArray], int i){
    mahasiswa temp = mhs[i];
    mhs[i] = mhs[i+1];
    mhs[i+1] = temp;
}

//fungsi untuk memilih 5 pendaftar terbaik
void display(mahasiswa mhs[maxArray], int n){
    //Bubble Sort untuk mengurutkan antrian berdasarkan Nilai Alpro dan Kalkulus
    for(int i = front; i<rear; i++){
        for(int j = front; j<rear; j++){
            if(mhs[j+1].alpro > mhs[j].alpro){
                Tukar(mhs, j);
            };
            if((mhs[j+1].alpro == mhs[j].alpro) && (mhs[j+1].kalkulus > mhs[j].kalkulus)){
                Tukar(mhs, j);
            };
        }
    }

    //jika antrian kosong
    if (count == 0){
        printf("Belum ada yang daftar\n");
        return;
    }
    else{
        int i = front, j = 0;
        while(j<n){
            printf("Nama: %s\tAlpro: %d\tKalkulus: %d\n", mhs[i].nama, mhs[i].alpro, mhs[i].kalkulus);
            i++; j++;
        }
    }
    

}

int main(){
    system("cls");
    mahasiswa mhs[maxArray];
    enqueue(mhs, "Eko", 50,20);
    enqueue(mhs, "Budi", 50,20);
    enqueue(mhs, "bambang", 60,20);
    enqueue(mhs, "Eka", 60,20);
    enqueue(mhs, "wawo", 60,20);
    enqueue(mhs, "Ame", 60,30);
    display(mhs, maxPendaftar);
    return 0;
}