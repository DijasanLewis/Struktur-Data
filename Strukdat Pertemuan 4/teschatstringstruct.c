#include <stdio.h>
#include <stdlib.h>

//deklarasi pointer
struct node
{
    int NIM;
    char nama[50];
    struct node *next;
};

typedef struct node *ptrnode;

//fungsi membuat node baru
ptrnode Create_Node(int NIM, char nama[50]){
    ptrnode NodeBaru;
    NodeBaru = (ptrnode)malloc(sizeof(struct node));
    NodeBaru->NIM = NIM;
    NodeBaru->nama = nama;
    NodeBaru->next = NULL;
    return(NodeBaru);
}
//fungsi menambah node dari ujung kiri (awal)
ptrnode insert_head(ptrnode head, int NIM, char *nama){
    ptrnode NodeBaru = Create_Node(NIM, nama);
    NodeBaru->next = head;
    head = NodeBaru;
    puts("Data baru sudah ditambahkan di ujung kiri (awal) daftar!\n");
    return(head);
}

int main(){
    int NIM;
    char nama[50];
    ptrnode head = NULL;

    system("cls");
    puts("Anda sedang membuat node baru di urutan pertama.");
    printf("Masukan NIM     : "); scanf("%d", &NIM);
    printf("Masukan Nama    : "); scanf("%[^\n]s", nama);
    head = insert_head(head, NIM, nama);
    system("cls");
}