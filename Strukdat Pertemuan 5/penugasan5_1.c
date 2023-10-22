/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 5 PENUGASAN BAGIAN 1
    Cobalah untuk memodifikasi potongan program pada pembuatan simpul awal,
    insert kanan, dan delete kanan sehingga pointer tail dideklarasikan dan selalu
    diperbaharui isinya saat penambahan dan penghapusan simpul dari kanan. 
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

typedef struct node *ptrnode;
ptrnode head = NULL;
ptrnode tail = NULL;


//fungsi membuat node baru
ptrnode createNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return(p);
}

//insert kiri
ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
    return(head);
}

//insert kanan
ptrnode insert_tail(ptrnode head, int nilai) {
    ptrnode new_node = createNode(nilai);
    if (tail != NULL) {
        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
    } else {
        head = new_node;
        tail = new_node;
    }
    return head;
}

//insert node setelah node tertentu
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari){
    //cari node sebelumnya yg ingin dicari
    if (tail->value == nilai_dicari)
    {
        head = insert_tail(head, nilai);
        return;
    };
    ptrnode cursor = head;
    while (cursor->value!=nilai_dicari)
    {
        cursor=cursor->next;
    }
    
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    new_node->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;

    return(head);
}

//insert node sebelum node tertentu
ptrnode insert_before(ptrnode head, int nilai, int nilai_dicari){
    if(head->value == nilai_dicari){
        head = insert_head(head, nilai);
        return;
    }
    else{
        //cari node yang dicari
        ptrnode cursor = head;
        while (cursor->value!=nilai_dicari)
        {
            cursor = cursor->next;
        }
        ptrnode new_node = createNode(nilai);
        new_node->prev = cursor->prev;
        new_node->prev->next = new_node;
        new_node->next = cursor;
        cursor->prev = new_node;
    }
    return(head);
}

//hapus node pertama
ptrnode remove_first(ptrnode head){
    if(head == NULL) 
        return;
    
    ptrnode first = head;
    head = head->next;
    head->prev = NULL;
    first->next = NULL;

    free(first);
    return(head);
}

//hapus node terakhir
ptrnode remove_last(ptrnode tail) {
    if (tail == NULL) {
        return;
    }
    
    ptrnode dummy = tail;
    tail = tail->prev;
    tail->next = NULL;
    dummy->prev = NULL;
    free(dummy);
    
    return tail;
}

//hapus node tertentu
ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while (cursor->next != NULL)
    {
        if(cursor->next->value == nilai){
            break; //keluar dari iterasi
        };
        cursor=cursor->next;
    }

    if(cursor!=NULL){
        ptrnode dummy = cursor->next;
        cursor->next = dummy->next;
        dummy->next->prev = cursor;
        dummy->next = NULL;
        dummy->prev = NULL;
        free(dummy);
    }
    return(head);
}

//cetak daftar nilai node
void cetakdaftar(ptrnode head){
    int i = 1;
    ptrnode n = head;
    while (n!=NULL)
    {
        printf("Node %d = %d\n", i, n->value);
        n = n->next;
        i++;
    }
}

int main(){
    head = (ptrnode)malloc(sizeof(struct node));
    tail = head;
    head->value = 10;
    head->next = NULL;
    head->prev = NULL;

    //PEMBUATAN SEBUAH SIMPUL:
    //CARA 1: deklarasikan node, kemudian deklarasi pointer
    //dengan alamat node yang dideklarasikan
    struct node node_dua;
    ptrnode dua = &node_dua;
    dua->value = 20;
    dua->next = NULL;
    dua->prev = NULL;

    head->next = dua;
    dua->prev = head;

    //CARA 2: deklarasi pointer, lalu deklarasi struct node
    //sekaligus mengalokasikan memori untuk struct node yg disimpan dalam pointer
    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    dua->next = tiga;

    tiga->value = 30;
    tiga->next = empat;
    tiga->prev = dua;

    empat->value = 40;
    empat->next = NULL;
    empat->prev = tiga;

    //membuat node baru dengan fungsi createNode
    ptrnode lima = createNode(50);
    empat->next = lima;
    lima->prev = empat;
    tail = lima;
    
    puts("");
    cetakdaftar(head);    
    printf("Tail sekarang = %d\n", tail->value);

    // Tambahkan node baru dengan value = 99 sebagai head
    head = insert_head(head, 99);
    // Tambahkan node baru dengan value = 11 sebagai tail
    head = insert_tail(head, 11);
    /* Tambahkan node baru dengan value = 60 setelah node
    dengan value 50 */
    head = insert_after(head, 60, 50);
    /* Tambahkan node baru dengan value = 35 sebelum node
    dengan value 40 */
    head = insert_before(head, 35, 40);
   
    puts("");
    cetakdaftar(head);
    printf("Tail sekarang = %d\n", tail->value);

    /* Hapus node head */
    head = remove_first(head);  
    /* Hapus node tail */
    tail = remove_last(tail);
    /* Hapus node di tengah */
    head = remove_middle(head, 30);

    puts("");
    cetakdaftar(head);
    printf("Tail sekarang = %d\n", tail->value);
}