#include <stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

void create (Queue *q,int s){
    q->size = s;
    q->Q = (int *)malloc(s * sizeof(int));
    q->front = q->rear = -1;
}

void enqueue (Queue *q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
    } else { // move rear and insert the element
        q->rear++;
        q->Q[q->rear] = x;
    }
    return;
}

int dequeue (Queue *q) {
    int x = -1;

    if(q->rear == q->front) { // -1
        printf("Queue is empty\n");
    } else {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty (Queue q) {
    return q.front == q.rear;
}

int isFull (Queue q) {
    return q.rear == q.size - 1;
}

void display (Queue q) {
    for(int i = q.front + 1; i <= q.rear; i++) {
        printf("%d ", q.Q[i]);
    }
    printf("\n");
}

int main() {
    Queue q;
    int n;

    printf("Enter queue size: \n");
    scanf("%d", &n);
    create(&q,n);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    display(q);
    return 0;
}