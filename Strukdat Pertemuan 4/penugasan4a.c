/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 4 PENUGASAN BAGIAN 1
    Buatlah fungsi untuk menghitung jumlah node dalam sebuah linked list! (looping
    sama seperti pada saat menampilkan nilai dari linked list)
*/

#include <stdio.h>
#include <stdlib.h>

//deklarasi pointer
struct node
{
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

//fungsi membuat node baru
ptrnode Create_Node(int nilai){
    ptrnode NodeBaru;
    NodeBaru = (ptrnode)malloc(sizeof(struct node));
    NodeBaru->value = nilai;
    NodeBaru->next = NULL;
    return(NodeBaru);
}

//fungsi menambah node dari ujung kiri (awal)
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode NodeBaru = Create_Node(nilai);
    NodeBaru->next = head;
    head = NodeBaru;
    puts("Node baru sudah ditambahkan di ujung kiri (awal) daftar!\n");
    return(head);
}

//fungsi menambah node dari ujung kanan (akhir)
ptrnode insert_tail(ptrnode head, int nilai){
    ptrnode tail = head;
    ptrnode NodeBaru = Create_Node(nilai);
    //jika daftar kosong
    if (head == NULL){
        head = NodeBaru;
    }
    //mencari node terakhir
    else{
        while (tail->next != NULL){
            tail = tail->next;
        };
        tail->next = NodeBaru;
    }
    
    puts("Node baru sudah ditambahkan di ujung kanan (akhir) daftar!\n");
    return(head);
}

//fungsi menambah node setelah node tertentu
ptrnode insert_after(ptrnode head, int nilai, int nilai_sebelumnya){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    //mencari node yang sesuai
    ptrnode kursor = head;
    while (kursor->value != nilai_sebelumnya)
    {
        kursor = kursor->next;
        if (kursor == NULL)
        {
            printf("Node bernilai %d tidak terdaftar!\n\n", nilai_sebelumnya);
            return (head);
        }
        
    }
    
    ptrnode NodeBaru = Create_Node(nilai);
    NodeBaru->next = kursor->next;
    kursor->next = NodeBaru;
    printf("Node baru sudah ditambahkan setelah node bernilai %d!\n\n", nilai_sebelumnya);
    return(head);
}

//fungsi menambah node sebelum node tertentu
ptrnode insert_before(ptrnode head, int nilai, int nilai_setelahnya){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    //mencari node yang sesuai
    if (head->value == nilai_setelahnya)
    {
        head = insert_head(head, nilai);
    }
    else
    {
        ptrnode Kursor, SebelumKursor;
        Kursor = head;
        do
        {
            SebelumKursor = Kursor;
            Kursor = Kursor->next;
            if (Kursor == NULL)
            {
                printf("Node bernilai %d tidak terdaftar!\n\n", nilai_setelahnya);
                return (head);
            }
        } while (Kursor->value != nilai_setelahnya);
        
        
        ptrnode NodeBaru = Create_Node(nilai);
        NodeBaru->next = Kursor;
        SebelumKursor->next = NodeBaru;
    }
    printf("Node baru sudah ditambahkan sebelum node bernilai %d!\n\n", nilai_setelahnya);
    return(head);
}

//fungsi menghapus node pertama (head)
ptrnode remove_head(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    ptrnode NodePertama = head;
    head = head->next;
    NodePertama->next = NULL;
    free(NodePertama);
    puts("Node pertama telah dihapus!\n");
    return(head);
}

//fungsi menghapus node terakhir (tail)
ptrnode remove_tail(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    ptrnode NodeTerakhir = head;
    ptrnode NodeSebelumTerakhir = NULL;

    while (NodeTerakhir->next != NULL)
    {
        NodeSebelumTerakhir = NodeTerakhir;
        NodeTerakhir = NodeTerakhir->next;
    }
    
    NodeSebelumTerakhir->next = NULL;
    free(NodeTerakhir);
    puts("Node terakhir telah dihapus!\n");
    return(head);
}

//fungsi menghapus node tertentu
ptrnode remove_node(ptrnode head, int nilai){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    
    //mencari node yang sesuai
    ptrnode Kursor = head;
    while (Kursor != NULL)
    {
        if(Kursor->next->value == nilai){
            break;
        }
        Kursor = Kursor->next;
    }
    //menghapus node yang sesuai
    if(Kursor != NULL){
        ptrnode Dummy = Kursor->next; //node yang ingin dihapus dimasukkan dalam dummy
        Kursor->next = Dummy->next;
        Dummy->next = NULL;
        free(Dummy);
        printf("Node yang bernilai %d berhasil dihapus\n", nilai);
    }
    return(head);
}

//fungsi menghapus linked list
ptrnode delete_linkedlist(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\n");
        return(head);
    }
    
    while (head != NULL)
    {
        ptrnode Dummy = head;
        head = head->next;
        Dummy->next = NULL;
        free(Dummy);
    }
    puts("Linked list telah dihapus!");
    return(head);
}

//fungsi menampilkan daftar nilai
void tampilkan_daftar(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    
    int i = 1;
    ptrnode n = head;
    puts("Daftar Nilai linked list :");
    while (n!=NULL){
        printf("Node ke-%d : %d\n", i, n->value);
        n = n->next;
        i++;
    };
    puts("");
}

//fungsi menampilkan jumlah node
void jumlah_node(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR NILAI KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    int count = 0;
    while (head!=NULL)
    {
        head = head->next;
        count++;
    };
    printf("Jumlah node adalah %d\n", count);
}

void Jeda(){
    int c;
    puts("Tekan Enter untuk melanjutkan....");
    c = getchar();
    getchar();
}

int main(){
    int pilih, nilai, nilaisyarat;
    ptrnode head = NULL;
    // MENU
    while (1)
    {
        system("cls");
        puts("===== PROGRAM SINGLE LINKED LIST =====");
        puts("\nSilahkan pilih menu berikut!");
        puts("\nMEMASUKKAN NILAI:");
        puts(" 1. Insert nilai di urutan pertama");
        puts(" 2. Insert nilai di urutan terakhir");
        puts(" 3. Insert nilai setelah nilai tertentu");
        puts(" 4. Insert nilai sebelum nilai tertentu");
        puts("\nMENGHAPUS NILAI:");
        puts(" 5. Hapus nilai di urutan pertama");
        puts(" 6. Hapus nilai di urutan terakhir");
        puts(" 7. Hapus nilai tertentu");
        puts(" 8. Hapus/free linked list ");
        puts("\nMENAMPILKAN DAFTAR NILAI:");
        puts(" 9. Tampilkan daftar nilai linked list");
        puts("**10. Tampilkan jumlah node**");
        puts("\n11. KELUAR");                
        
        printf("\nPilihan Anda = "); scanf("%d", &pilih);
        switch (pilih){
            case 1:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru di urutan pertama.");
                printf("Masukan Nilai = "); scanf("%d", &nilai);
                head = insert_head(head, nilai);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 2:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru di urutan terakhir.");
                printf("Masukan Nilai = "); scanf("%d", &nilai);
                head = insert_tail(head, nilai);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 3:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru setelah node tertentu.");
                printf("Masukan Nilai = "); scanf("%d", &nilai);
                printf("Masukan nilai tersebut setelah nilai: "); scanf("%d", &nilaisyarat);
                head = insert_after(head, nilai, nilaisyarat);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 4:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru sebelum node tertentu.");
                printf("Masukan Nilai = "); scanf("%d", &nilai);
                printf("Masukan nilai tersebut sebelum nilai: "); scanf("%d", &nilaisyarat);
                head = insert_before(head, nilai, nilaisyarat);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 5:
                system("cls");
                tampilkan_daftar(head);
                head = remove_head(head);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 6:
                system("cls");
                tampilkan_daftar(head);
                head = remove_tail(head);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 7:
                system("cls");
                tampilkan_daftar(head);
                printf("Masukan nilai yang ingin dihapus = "); scanf("%d", &nilai);
                head = remove_node(head, nilai);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 8:
                system("cls");
                head = delete_linkedlist(head);
                Jeda();
                system("cls");
                break;
            case 9:
                system("cls");
                tampilkan_daftar(head);
                Jeda();
                break;
            case 10:
                system("cls");
                tampilkan_daftar(head);
                jumlah_node(head);
                Jeda();
                break;
            case 11:
                system("cls");
                puts("Terima kasih telah menggunakan program ini...\nHAVE A NICE DAY! (^_^)\n");
                Jeda();
                exit(1);
            default:
                system("cls");
                puts("Mohon maaf, pilihan tersebut tidak tersedia...\n");
                puts("Silahkan memilih menu yang tersedia (1-12)");
                Jeda();
                break;
        }
    }
    return 0;
}