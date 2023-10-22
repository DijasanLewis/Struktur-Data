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
    while (cursor != NULL)
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
    int pilih, nilai;
    ptrnode head = NULL;
    /* MENU*/
    while (1)
    {
        puts("========== PROGRAM SINGLE LINKED LIST ==========");
        puts(" 1. Insert nilai di urutan pertama");
        puts(" 2. Insert nilai di urutan terakhir");
        puts(" 3. Insert nilai setelah nilai tertentu");
        puts(" 4. Insert nilai sebelum nilai tertentu");
        puts(" 5. Hapus nilai di urutan pertama");
        puts(" 6. Hapus nilai di urutan terakhir");
        puts(" 7. Hapus nilai tertentu");
        puts(" 8. Tampilkan daftar nilai linked list");
        puts(" 9. Tampilkan nilai secara reversed");
        puts("**10. Tampilkan jumlah node**");
        puts("11. Hapus/free linked list ");
        puts("12. Keluar");
        printf("Pilihan Anda = "); scanf("%d", &pilih);

        switch (pilih)
        {
        case 1:
        {
            printf("Masukan Nilai = "); scanf("%d", &nilai);
            insert_head(head, nilai);
            system("cls");
            break;
        }
                  
        default:
            break;
        }
    }
    
    

    /* MENU*/

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