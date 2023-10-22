
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *prev;
    struct node *next;
};

typedef struct node *ptrnode;

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
ptrnode insert_tail(ptrnode head, int nilai){
    //mencari node terakhir
    ptrnode tail = head;
    while (tail->next!=NULL)
    {
        tail = tail->next;
    }
    //buat node baru
    ptrnode new_node = createNode(nilai);
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
    
    return(head);
}

//insert node setelah node tertentu
ptrnode insert_after(ptrnode head, int nilai, int nilai_dicari){
    //cari node sebelumnya yg ingin dicari
    ptrnode cursor = head;
    while (cursor->value!=nilai_dicari)
    {
        cursor=cursor->next;
    }
    
    ptrnode new_node = createNode(nilai);
    new_node->next = cursor->next;
    cursor->next->prev = new_node;
    new_node->prev = cursor;
    cursor->next = new_node;

    return(head);
}

//insert node sebelum node tertentu
ptrnode insert_before(ptrnode head, int nilai, int nilai_dicari){
    if(head->value = nilai_dicari)
        head = insert_head(head, nilai);
    else{
        //cari node yang dicari
        ptrnode cursor = head;
        while (cursor->value!=nilai_dicari)
        {
            cursor = cursor->next;
        }
        ptrnode new_node = createNode(nilai);
        new_node->prev = cursor->prev;
        cursor->prev->next = new_node;
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
ptrnode remove_last(ptrnode head){
    if (head == NULL)
    {
        return;
    }
    //cursor bantuan satu lagi (prev_tail) tidak dibutuhkan
    ptrnode tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    
    tail->prev = NULL;
    tail->prev->next = NULL;
    free(tail);
    return head;
}

//hapus node tertentu
ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while (cursor->next = NULL)
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


int main(){
    ptrnode head = NULL;
    ptrnode tail = NULL;
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

    // Tambahkan node baru dengan value = 99 sebagai head
    head = insert_head(head, 99);
    head = insert_tail(head, 11);
    /* Tambahkan node baru dengan value = 60 setelah node
    dengan value 50 */
    head = insert_after(head, 60, 50);
    /* Tambahkan node baru dengan value = 35 sebelum node
    dengan value 40 */
    head = insert_before(head, 35, 40);

    

    //program menampilkan nilai linked list
    int i = 1;
    ptrnode n = head;
    while (n!=NULL)
    {
        printf("Node %d = %d\n", i, n->value);
        n = n->next;
        i++;
    }
    /* Hapus node head */
    head = remove_first(head);  
    /* Hapus node tail */
    head = remove_last(head);
    /* Hapus node di tengah */
    head = remove_middle(head, 30);
}