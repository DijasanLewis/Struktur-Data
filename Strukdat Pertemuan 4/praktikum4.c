#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

typedef struct node *ptrnode;

ptrnode creatNode(int nilai){
    ptrnode p;
    p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    return p;
}

ptrnode insert_head(ptrnode head, int nilai){
    ptrnode new_node = creatNode(nilai);
    new_node->next = head;
    head = new_node;

    return(head);
}

ptrnode insert_tail(ptrnode head, int nilai){
    /* iterasi mencari node terakhir*/
    ptrnode tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    };

    /* buat node baru */
    ptrnode new_code = creatNode(nilai);
    tail->next=new_code;

    return(head);
}

ptrnode insert_after(ptrnode head, int nilai, int prev_nilai){
    /* cari node sebelumnya, dimulai dari node head/ first */
    ptrnode cursor = head;
    while(cursor->value != prev_nilai){
        cursor = cursor->next;
    }

    ptrnode new_node = creatNode(nilai);
    new_node->next = cursor->next;
    cursor->next = new_node;

    return(head);
}

ptrnode insert_before(ptrnode head, int nilai, int next_nilai){
    if (head->value == next_nilai){
        head = insert_head(head, nilai);
    }
    else{
        ptrnode cursor, prevcursor;
        cursor = head;

        do{
            prevcursor = cursor;
            cursor = cursor->next;
        }
        while (cursor->value != next_nilai);

        ptrnode new_code = creatNode(nilai);
        new_code->next = cursor;
        prevcursor->next = new_code;
    }
    return(head);
}

ptrnode remove_first(ptrnode head){
    if (head == NULL)
        return;

    ptrnode first = head;
    head = head->next;

    first->next = NULL;
    free(first);

    return(head);
}

ptrnode remove_last(ptrnode head){
    if(head == NULL)
        return;

    ptrnode tail = head;
    ptrnode prevtail = NULL;
    while (tail->next != NULL)
    {
        prevtail = tail;
        tail = tail->next;
    };

    prevtail->next = NULL;
    free(tail);

    return(head);    
}

ptrnode remove_middle(ptrnode head, int nilai){
    ptrnode cursor = head;
    while (cursor != nilai)
    {
        if (cursor->next->value == nilai)
            break; //keluar dari iterasi
        cursor = cursor -> next;
    }
    
    if(cursor!=NULL){
        ptrnode temp = cursor->next;
        cursor->next = temp->next;
        temp->next = NULL;
        free(temp);
    }
    return(head);
}

ptrnode dispose(ptrnode head){
    if (head == NULL)
        return;
    while (head!=NULL)
    {
        ptrnode temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }
    printf("Semua node telah dihilangkan\n");
    return(head);
}

int main(){
    ptrnode head = NULL;
    ptrnode dua = NULL;
    ptrnode tiga = NULL;
    ptrnode empat = NULL;

    head = (ptrnode)malloc(sizeof(struct node));
    dua = (ptrnode)malloc(sizeof(struct node));
    tiga = (ptrnode)malloc(sizeof(struct node));
    empat = (ptrnode)malloc(sizeof(struct node));

    head->value = 10;
    head->next = dua;
    dua->value = 20;
    dua->next = tiga;   
    tiga->value = 30;
    tiga->next = empat;
    empat->value = 40;
    empat->next = NULL;


    ptrnode lima = creatNode(50);
    empat->next = lima;

    /* Tambahkan node baru dengan value = 99 sebagai head */
    head = insert_head(head, 99);
    head = insert_tail(head, 11);
    head = insert_after(head, 60, 50);

    /* Tambahkan node baru dengan value = 35
    sebelum node dengan value 99 */
    head = insert_before(head, 35, 40);

    /* Hapus node head */
    head = remove_first(head);

    /* Hapus node tail */
    head = remove_last(head);

    /* Hapus node di tengah */
    head = remove_middle(head, 30);

    /* Hapus/free linked list */
    //head = dispose(head);

    int i = 1;
    ptrnode n = head;
    printf("Daftar nilai Linked List: \n");
    while (n != NULL)
    {
        printf("Node ke-%d: %d\n", i, n->value);
        n = n->next;
        i++;
    };
    puts("");
    
    return 0;
}