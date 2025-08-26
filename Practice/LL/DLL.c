#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* head;

void init (int val) {
    Node* newnode;

    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = NULL;
}