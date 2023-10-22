/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 4 PENUGASAN BAGIAN 3
    Buat program untuk menyimpan data students berisi int NIM, char nama[50]
secara dinamis!
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//deklarasi pointer
struct node
{
    int NIM;
    char nama[50];
    struct node *next;
};

typedef struct node *ptrnode;

//fungsi membuat node baru
ptrnode Create_Node(int NIM, char *nama){
    ptrnode NodeBaru;
    NodeBaru = (ptrnode)malloc(sizeof(struct node));
    NodeBaru->NIM = NIM;
    strcpy(NodeBaru->nama, nama);
    NodeBaru->next = NULL;
    return(NodeBaru);
}

//fungsi menambah node dari ujung kiri (awal)
ptrnode insert_head(ptrnode head, int NIM, char *nama){
    ptrnode NodeBaru = Create_Node(NIM, nama);
    NodeBaru->next = head;
    head = NodeBaru;
    printf("Data %s dengan NIM %d berhasil ditambahkan di awal daftar!\n\n", NodeBaru->nama, NodeBaru->NIM);
    return(head);
}

//fungsi menambah node dari ujung kanan (akhir)
ptrnode insert_tail(ptrnode head, int NIM, char *nama){
    ptrnode tail = head;
    ptrnode NodeBaru = Create_Node(NIM, nama);
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
    
    printf("Data %s dengan NIM %d berhasil ditambahkan di akhir daftar!\n\n", NodeBaru->nama, NodeBaru->NIM);
    return(head);
}

//fungsi menambah node setelah node tertentu
ptrnode insert_after(ptrnode head, int NIM, char *nama, int NIM_sebelumnya){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    //mencari node yang sesuai
    ptrnode kursor = head;
    while (kursor->NIM != NIM_sebelumnya)
    {
        kursor = kursor->next;
        if (kursor == NULL)
        {
            printf("Mahasiswa dengan NIM %d tidak terdaftar!\n\n", NIM_sebelumnya);
            return (head);
        }
        
    }
    
    ptrnode NodeBaru = Create_Node(NIM, nama);
    NodeBaru->next = kursor->next;
    kursor->next = NodeBaru;
    printf("Data %s dengan NIM %d berhasil ditambahkan setelah data mahasiswa dengan NIM %d!\n\n", NodeBaru->nama, NodeBaru->NIM, NIM_sebelumnya);
    return(head);
}

//fungsi menambah node sebelum node tertentu
ptrnode insert_before(ptrnode head, int NIM, char *nama, int NIM_setelahnya){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    //mencari node yang sesuai
    if (head->NIM == NIM_setelahnya)
    {
        head = insert_head(head, NIM, nama);
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
                printf("Mahasiswaw dengan NIM %d tidak terdaftar!\n\n", NIM_setelahnya);
                return (head);
            }
        } while (Kursor->NIM != NIM_setelahnya);
        
        
        ptrnode NodeBaru = Create_Node(NIM, nama);
        NodeBaru->next = Kursor;
        SebelumKursor->next = NodeBaru;
        printf("Data %s dengan NIM %d berhasil ditambahkan sebelum data mahasiswa dengan NIM %d!\n\n", NodeBaru->nama, NodeBaru->NIM, NIM_setelahnya);
    }

    return(head);
}

//fungsi menghapus node pertama (head)
ptrnode remove_head(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    ptrnode NodePertama = head;
    head = head->next;
    NodePertama->next = NULL;
    free(NodePertama);
    puts("Data pertama telah dihapus!\n");
    return(head);
}

//fungsi menghapus node terakhir (tail)
ptrnode remove_tail(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
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
    puts("Data terakhir telah dihapus!\n");
    return(head);
}

//fungsi menghapus node tertentu
ptrnode remove_node(ptrnode head, int NIM){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    
    //mencari node yang sesuai
    ptrnode Kursor = head;
    while (Kursor != NULL)
    {
        if(Kursor->next->NIM == NIM){
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
        printf("Data mahasiswa dengan NIM %d berhasil dihapus\n\n", NIM);
    }
    return(head);
}

//fungsi menghapus linked list
ptrnode delete_linkedlist(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\n");
        return(head);
    }
    
    while (head != NULL)
    {
        ptrnode Dummy = head;
        head = head->next;
        Dummy->next = NULL;
        free(Dummy);
    }
    puts("Daftar Mahasiswa berhasil dihapus!");
    return(head);
}

//fungsi menampilkan daftar NIM
void tampilkan_daftar(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    
    int i = 1;
    ptrnode n = head;
    puts("Daftar Mahasiswa:");
        puts  ("Nomor\t   NIM\t\t      NAMA");
    while (n!=NULL){
        printf("  %d\t(%d)\t%s\n", i, n->NIM, n->nama);
        n = n->next;
        i++;
    };
    puts("");
}

//fungsi menampilkan jumlah node
void jumlah_node(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    int count = 0;
    while (head!=NULL)
    {
        head = head->next;
        count++;
    };
    printf("Jumlah mahasiswa adalah %d orang.\n", count);
}

ptrnode reverse(ptrnode head){
    //jika linked list kosong
    if (head==NULL){
        puts("DAFTAR MAHASISWA KOSONG!\nSilakan mengisi daftar terlebih dahulu...\n");
        return(head);
    }
    struct node *current, *prev, *next;
    current = head;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    puts("Urutan daftar mahasiswa sudah dibalik!");
    return head;   
}

void Jeda(){
    int c;
    puts("Tekan Enter untuk melanjutkan....");
    c = getchar();
    getchar();
}

int main(){
    int pilih, NIM, NIMsyarat;
    char nama[50];
    ptrnode head = NULL;
    // MENU
    while (1)
    {
        system("cls");
        puts("======= PROGRAM DATA MAHASISWA =======");
        puts("\nSilahkan pilih menu berikut!");
        puts("\nMEMASUKKAN DATA:");
        puts(" 1. Insert data di urutan pertama");
        puts(" 2. Insert data di urutan terakhir");
        puts(" 3. Insert data setelah NIM tertentu");
        puts(" 4. Insert data sebelum NIM tertentu");
        puts("\nMENGHAPUS DATA:");
        puts(" 5. Hapus data di urutan pertama");
        puts(" 6. Hapus data di urutan terakhir");
        puts(" 7. Hapus data tertentu");
        puts(" 8. Hapus data mahasiswa");
        puts("\nMENAMPILKAN DAFTAR MAHASISWA:");
        puts(" 9. Tampilkan daftar mahasiswa");
        puts("10. Tampilkan jumlah mahasiswa");
        puts("11. Tampilkan daftar mahasiswa secara reversed");
        puts("\n12. KELUAR");                
        
        printf("\nPilihan Anda = "); scanf("%d", &pilih);
        switch (pilih){
            case 1:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru di urutan pertama.");
                printf("Masukan NIM     : "); scanf("%d", &NIM);
                printf("Masukan Nama    : "); scanf(" %[^\n]s", nama);
                head = insert_head(head, NIM, nama);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 2:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru di urutan terakhir.");
                printf("Masukan NIM     : "); scanf("%d", &NIM);
                printf("Masukan Nama    : "); scanf(" %[^\n]s", nama);
                head = insert_tail(head, NIM, nama);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 3:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru setelah node tertentu.");
                printf("Masukan NIM     : "); scanf("%d", &NIM);
                printf("Masukan Nama    : "); scanf(" %[^\n]s", nama);
                printf("Masukan NIM tersebut setelah NIM: "); scanf("%d", &NIMsyarat);
                head = insert_after(head, NIM, nama, NIMsyarat);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 4:
                system("cls");
                tampilkan_daftar(head);
                puts("Anda sedang membuat node baru sebelum node tertentu.");
                printf("Masukan NIM     : "); scanf("%d", &NIM);
                printf("Masukan Nama    : "); scanf(" %[^\n]s", nama);
                printf("Masukan NIM tersebut sebelum NIM: "); scanf("%d", &NIMsyarat);
                head = insert_before(head, NIM, nama, NIMsyarat);
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
                printf("Masukan NIM yang ingin dihapus = "); scanf("%d", &NIM);
                head = remove_node(head, NIM);
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
                tampilkan_daftar(head);
                head = reverse(head);
                tampilkan_daftar(head);
                Jeda();
                system("cls");
                break;
            case 12:
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