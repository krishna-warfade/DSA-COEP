// head -> Node1->Node2
#include <stdlib.h>
#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

int main()
{
    Node *Head = NULL;

    Node *Node1 = malloc(sizeof(Node));
    Node *Node2 = malloc(sizeof(Node));

    Head = Node1;
    Node1->data = 10;
    (*Node1).next = Node2;
    Node2->data = 20;
    Node2->next = NULL;

    printf("%d\n", Head->data);
    printf("%d\n", Head->next->data);
    // This will print a garbage value
}