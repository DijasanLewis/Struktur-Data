#include <stdio.h>
#include <stdlib.h>

//Deklarasi stack
struct node
{
    int data;
    struct node *next;
};

typedef struct node *item;
item top;

//inisialisasi stack
void initialize(){
    top = NULL;
}

//fungsi push
void push(int value){
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = top;
    top = new_node;
}

//fungsi pop
int pop(){
    if (top == NULL){
        printf("STACK SUDAH KOSONG!");
        return 0;
    }
    else{
        item dummy;
        dummy = top;
        top = top->next;
        free(dummy);
        return(1);
    }
}

//fungsi display
void display(item top){
    if (top == NULL)
        puts("STACK KOSONG!");
    else{
        puts("ISI STACK: ");
        printf("%d\n", top->data);
        if (top->next != NULL)
            display(top->next);
    }
}

void jeda(){
    int c;
    puts("\nTekan ENTER untuk melanjutkan...");
    c = getchar();
    getchar();
    system("cls");
}

int main(){
    int choice = 0;
    system("cls");
    do{
        puts("== PROGRAM STACK ==\n");
        puts("1. Display");
        puts("2. Tambah (Push)");
        puts("3. Hapus (Pop)");
        puts("4. Exit\n");
        printf("Masukan Pilihan : ");
        scanf("%d", &choice);
        puts("");
        switch (choice)
        {
        case 1:
            display(top);
            break;
        case 2:
            printf("Masukan item untuk ditambahkan : ");
            int item = 0;
            scanf("%d", &item);
            push(item);
            break;
        case 3:
            pop();
            break;
        case 4:
            puts("KELUAR");
            break;
        default:
            puts("PILIHAN TIDAK VALID!");
            puts("Silahkan memilih menu yang tersedia (1-4).");
            break;
        }  
        jeda();
    }
    while(choice != 4);
    return (0);
}