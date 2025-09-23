#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// USING ARRAY

typedef struct Node {
    int front, rear;
    int size;
    int *Q;
} Node;

void create (Node* q, int size) {
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
}

void push (Node *q, int x) {
    if (q->rear == q->size - 1)
        printf("Queue is Full\n");
    else
        q->Q[++(q->rear)] = x;
    return;
}

int pop (Node *q) {
    return (q->front == q->rear) ? -1 : q->Q[++(q->front)];
}

void display (Node q) {
    for (int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main () {
    Node q;
    create(&q, 5);
    push(&q, 90);
    display(q);
    push(&q, 20);
    display(q);
    push(&q, 30);
    display(q);
    printf("Popped value: %d\n",pop(&q));
    display(q);
    return 0;
}