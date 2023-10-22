#include <stdio.h>
#include <stdlib.h>

#define N 10
int stack[N], top;

void display(int stack[]){
    if (top >= 0){
        printf("ISI STACK : \n");
        for(int i = top; i>=0; i--){
            printf("%d\n", stack[i]);
        }
    }
    else printf("STACK KOSONG\n");
}

void push(int stack[], int item){
    if(top == N-1)
        printf("\n STACK PENUH! Tidak dapat ditambahkan item baru. \n");
    else{
        top++;
        stack[top]=item;
    }
}

void pop(int stack[]){
    if (top == -1)
        printf("STACK SUDAH KOSONG!\n");
    else{
        int deleteditem = stack[top];
        top--;
        printf("%d telah terhapus", deleteditem);
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
    top = -1;
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
            display(stack);
            break;
        case 2:
            printf("Masukan item untuk ditambahkan : ");
            int item = 0;
            scanf("%d", &item);
            push(stack, item);
            break;
        case 3:
            pop(stack);
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