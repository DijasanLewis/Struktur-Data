#include <stdio.h>
#include <stdlib.h>

struct Mynode{
    int data;
    struct Mynode* next;

};

int main(){
    struct Mynode* head = NULL;
    struct Mynode* dua = NULL;

    head = (struct Mynode*)malloc(8*sizeof(struct Mynode));
    dua = (struct Mynode*)malloc(sizeof(struct Mynode));

    head->data = 1;
    head->next = dua;

    printf("Ukuran Struct Mynode: %d\n", sizeof(struct Mynode *));
    printf("Ukuran Head: %d\n", sizeof(head));
    dua->data = 2;
    dua->next = NULL;

    /*printf("Isi dari linked list :\n");
    int n = head;
    while(n != NULL){
        printf("%d\n", n->data);
        n = n->next;
    }
    */
}