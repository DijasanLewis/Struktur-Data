#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//deklarasi elemen queue
struct node
{
    int data;
    struct node *next;
};
typedef struct node *item;

//deklarasi struktur queue
struct queue
{
    int count;
    item front;
    item rear;
};
typedef struct queue *antrian;

//inisialisasi queue
void initialize (antrian q){
    q->count = 0;
    q->front = NULL;
    q->rear  = NULL;
}

//jika queue kosong, fungsi isempty mengeluarkan TRUE
bool isempty(antrian q){
    return (q->rear == NULL);
}

//fungsi enqueue, menambah elemen baru ke antrian setelah rear
void q_insert (antrian q, int value){
    item new_node;
    new_node = (item)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;
    if(!isempty(q)){
        q->rear->next = new_node;
        q->rear = new_node;
        //jika antrian tidak kosong,
        //new_node menjadi rear baru
    }
    else{
        q->front = q->rear = new_node;
        //jika antrian kosong.
        //new node menjadi front dan rear
    }
    q->count++;
}

//fungsi dequeue, menghapus elemen front di antrian
void q_remove(antrian q){
    if(q == NULL){
        puts("Antrian Kosong!");
        return;
    }
    
    item tmp;
    tmp = q->front;
    q->front = q->front->next;
    q->count--;
    free(tmp);
}

void display(item front){
    if (front != NULL){
        do{
            printf("%d\n", front->data);
            front = front->next;
        } while(front != NULL);        
    }
}

int main(){
    antrian q;
    q = (antrian)malloc(sizeof(struct node));
    initialize(q);

    q_insert(q,10);
    q_insert(q,20);
    q_insert(q,30);
    q_insert(q,40);
    printf("Queue sebelum dequeue\n");
    display(q->front);
    q_remove(q);
    printf("Queue setelah dequeue\n");
    display(q->front);

    return 0;
}