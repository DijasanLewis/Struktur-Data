/*NAMA      : YEDIJA LEWI SURYADI
 *NIM       : 222212921
 *KELAS     : 2KS1
 *NO. ABSEN : 36
 STRUKTUR DATA MODUL 5 PENUGASAN BAGIAN 2
*/

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    Node* current = head;
    int i = 1;
    
    while (current != NULL) {
        printf("node %d: %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

Node* insert_node(Node* head, int data) {
    Node* new_node = createNode(data);
    
    if (head == NULL) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
    
    return head;
}

int main() {
    int n;
    printf("Input the number of nodes : ");
    scanf("%d", &n);
    
    Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        printf("input data for node %d : ", i + 1);
        scanf("%d", &data);
        head = insert_node(head, data);
    }
    
    puts("\nData entered in the list are :");
    print_list(head);
    
    int data;
    printf("Input data for the first node : ");
    scanf("%d", &data);
    
    Node* new_node = createNode(data);
    new_node->next = head;
    head = new_node;
    
    puts("\nAfter insertion the list are :");
    print_list(head);
    
    return 0;
}
