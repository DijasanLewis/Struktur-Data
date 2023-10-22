#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode createNode(int nilai) {
    ptrnode p = (ptrnode)malloc(sizeof(struct node));
    p->value = nilai;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void printNode(ptrnode head) {
    ptrnode temp = head;
    if (head == NULL) {
        printf("List kosong\n");
        return;
    }
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

ptrnode insert_tail(ptrnode head, int nilai) {
    ptrnode new_node = createNode(nilai);
    if (head == NULL) {
        head = new_node;
    } else {
        ptrnode tail = head;
        while (tail->next != NULL) {
            tail = tail->next;
        }
        tail->next = new_node;
        new_node->prev = tail;
    }
    return head;
}

void reverseList(ptrnode *head) {
    ptrnode current = *head;
    ptrnode temp = NULL;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

int main() {
    ptrnode head = NULL;

    head = insert_tail(head, 1);
    head = insert_tail(head, 2);
    head = insert_tail(head, 3);

    printf("Urutan asli:\n");
    printNode(head);

    reverseList(&head);

    printf("Setelah dibalik:\n");
    printNode(head);

    return 0;
}
