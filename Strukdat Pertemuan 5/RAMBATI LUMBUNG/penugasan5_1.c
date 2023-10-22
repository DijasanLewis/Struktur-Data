#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct node *ptrnode;

ptrnode tail = NULL;

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
        printf("List is empty\n");
        return;
    }
    printf("Nodes of double linked list: \n");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("\n");
}

ptrnode insert_head(ptrnode head, int nilai) {
    ptrnode new_node = createNode(nilai);
    new_node->next = head;
    if (head != NULL) {
        head->prev = new_node;
    }
    head = new_node;
    if (tail == NULL) {
        tail = head; 
    }
    return head;
}

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

ptrnode remove_last(ptrnode head) {
    if (head == NULL) {
        return NULL;
    }
    if (head->next == NULL) {
        free(head);
        head = NULL;
        tail = NULL;
    } else {
        ptrnode temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
    return head;
}

int main() {
    ptrnode head = NULL;
    
    head = insert_head(head, 99);
    head = insert_tail(head, 11);
    head = insert_tail(head, 22);

    printNode(head);
    head = remove_last(head);
    printNode(head);

    return 0;
}
