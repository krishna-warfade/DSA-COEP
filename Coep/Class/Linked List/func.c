#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* init(int val) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

// Insert at beginning
Node* insert(int val, Node* head) {
    Node* node = init(val);
    node->next = head;
    return node;   // return new head
}

// Delete from beginning
Node* del_begin(Node* head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    head = head->next;
    free(temp);
    return head;   // return new head
}

// Print list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* Head = NULL;  // local variable, no global

    Head = insert(10, Head);
    Head = insert(20, Head);
    Head = insert(30, Head);

    printf("Before Deletion:\n");
    printList(Head);

    Head = del_begin(Head);

    printf("After Deletion:\n");
    printList(Head);

    return 0;
}
