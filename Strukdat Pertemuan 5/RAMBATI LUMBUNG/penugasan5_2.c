#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    int nodeNumber = 1;
    
    printf("Data entered in the list are:\n");
    while (current != NULL) {
        printf("node %d: %d\n", nodeNumber, current->data);
        current = current->next;
        nodeNumber++;
    }
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    
    return head;
}

int main() {
    int n;
    printf("Input the number of nodes: ");
    scanf("%d", &n);
    
    Node* head = NULL;
    
    for (int i = 0; i < n; i++) {
        int data;
        printf("input data for node %d: ", i + 1);
        scanf("%d", &data);
        head = insertAtEnd(head, data);
    }
    
    printList(head);
    
    int newData;
    printf("\nInput data for the first node: ");
    scanf("%d", &newData);
    
    Node* newNode = createNode(newData);
    newNode->next = head;
    head = newNode;
    
    printf("\nafter insertion the list are:\n");
    printList(head);
    
    return 0;
}
