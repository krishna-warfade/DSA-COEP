#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;



Node* del_begin(Node *head) {
    if (head == NULL) return NULL;
    Node *temp = head;

    head = head->next;
    free(temp);
    return head;
}

int main()
{
    Node *Head = NULL;

    Node *Node1 = (Node *)malloc(sizeof(Node));
    Node *Node2 = (Node *)malloc(sizeof(Node));

    Head = Node1;
    Node1->data = 10;
    (*Node1).next = Node2;
    Node2->data = 20;
    Node2->next = NULL;

    printf("Before Deletion\n");
    printf("%d->", Head->data);
    printf("%d\n", Head->next->data);

    printf("After Deletion\n");
    Head = del_begin(Head);
    if (Head != NULL)
        printf("%d\n", Head->data);
    return 0;
}