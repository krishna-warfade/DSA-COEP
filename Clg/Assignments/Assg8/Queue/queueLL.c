#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// USING LL

typedef struct Node {
    int data;
    struct Node *next;
} Node;
Node *front = NULL;
Node *rear = NULL;
Node *q = NULL;

void push (int x) {
    Node *q = (Node*)malloc(sizeof(Node));

    if (q = NULL) {
        printf("Queue is Full\n");
        return;
    } else {
        q->data = x;
        q->next = NULL;
        if (front = NULL)
            front = rear = q;
        else {
            rear->next = q;
            rear = q;
        }
    }
}