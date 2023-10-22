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

    BAGIAN 1-3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Deklarasi Node
struct node{
    char nama[20];
    int alpro;
    int kalkulus;
    struct node *next;
};
typedef struct node *mhs;

int count = 0;
//soal 2
int maxPendaftar = 5; 
int pendaftar = 0;

//Fungsi membuat node baru
mhs newmhs(char a[], int alp, int kal){
    mhs temp = (mhs)malloc(sizeof(struct node));
    strcpy( temp->nama, a);
    temp->alpro = alp;
    temp->kalkulus = kal;
    temp->next = NULL;

    return temp;
}
//Fungsi dequeue
void dequeue(mhs* front){
    //kondisi queue kosong
    if (*front!=NULL){
        mhs temp = *front;
        (*front) = (*front)->next;
        free(temp);
    }
    else puts("Daftar Kosong");
}
//Fungsi enqueue
void enqueue(mhs* front, char n[], int alp, int kal){
    mhs temp = newmhs(n,alp,kal);
    if((*front)==NULL)
        (*front) = temp;
    else if ((*front)->alpro > alp){
        temp->next = (*front);
        (*front) = temp;
    }
    else if((*front)->alpro==alp){
        mhs start = (*front);
        while (start->next != NULL && start->next->kalkulus < kal){
            start = start->next;
        }
        temp->next = start->next;
        start->next = temp;
    }
    else{
        mhs start = (*front);
        while (start->next != NULL && start->next->alpro < alp){
            start = start->next;
        }
        if (start->next != NULL && start->next->alpro == alp){
            while (start->next != NULL && start->next->kalkulus < kal){
                start = start->next;
            }
        }
        temp->next = start->next;
        start->next = temp;
    }
    count++;
}

void display(mhs front)
{
    if(front == NULL){
        if (count == 0)
            printf("Belum ada yang daftar\n");
        return;
    }
    else{
        display(front->next); //soal 3, mengubah teknik rekursi agar rekursi terlebih dahulu baru kemudian printf dijalankan
        pendaftar++;
        if (pendaftar > maxPendaftar)
            return; //soal 2, jika sudah dicetak 5 pendaftar, fungsi berhenti
        printf("Nama: %s\tAlpro: %d\tKalkulus: %d\n", front->nama, front->alpro, front->kalkulus);
    }
}

int main(){
    system("cls");
    mhs wakil = NULL; //Untuk memperbaiki program agar yang muncul hanya yang diinputkan saja
    //maka wakil harus di NULL-kan terlebih dahulu
    enqueue(&wakil, "Eko", 50,20);
    enqueue(&wakil, "Budi", 50,20);
    enqueue(&wakil, "bambang", 60,20);
    enqueue(&wakil, "Eka", 60,20);
    enqueue(&wakil, "wawo", 60,20);
    enqueue(&wakil, "Ame", 60,30);
    display(wakil);
    return 0;
}