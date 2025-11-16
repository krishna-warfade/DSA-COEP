#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node* head = NULL;

Node* init(int val) {
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = val;
    node->next = NULL;
    return node;
}

void insert(int val) {
    Node* node = init(val);

    node->next = head;
    head = node; //directly updates head globally
}
/*
Node* del_begin(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;

    head = head->next;
    free(temp);
    return head;
}
*/

void del_begin() {
    if (head == NULL) return;
    Node *temp = head;

    head = head->next;
    free(temp);
}

void print () {
    Node* temp = head;

    while (temp != NULL) {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    // Node *Node1 = (Node *)malloc(sizeof(Node));
    // Node *Node2 = (Node *)malloc(sizeof(Node));
    // using **head in func. so no need to write Head = insert(10, head), head = ins... everytime
    insert(10);
    insert(20);
    insert(30);
    // Node1->data = 10;
    // (*Node1).next = Node2;
    // Node2->data = 20;
    // Node2->next = NULL;

    printf("Before Deletion\n");
    print();

    printf("After Deletion\n");
    del_begin();
    print();
    return 0;
}