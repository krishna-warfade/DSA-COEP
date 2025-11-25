/* Drawbacks of Linear Queue -
    to enqueue, rear = size-1 but if place avail before front ptr(already few elements deleted) i.e 
    * Cannot reuse places of deleted elements.

    Solutions -
    * Resetting pointers - at any time if queue is becoming empty, do front = rear = -1. (dosen't guarentee resuing of space)
    * Circular Queue - after finishing with the last element(rear), again start from front i.e
    * Front and rear move circularly.
*/

#include <stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

void create (Queue *q,int s) {
    q->size = s;
    q->Q = (int *)malloc(s * sizeof(int));
    q->front = q->rear = 0; // start from 0 not -1
}

void enqueue (Queue*q, int x) {
    if ((q->rear + 1) % q->size == q->front) { // if next place of rare = first, queue is full
        printf("Queue is full\n");
    } else { // move rear and insert the element
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
    return;
}

int dequeue (Queue*q) {
    int x = -1;

    if(q->rear == q->front) { // 0
        printf("Queue is empty\n");
    } else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}

void display (Queue q) {
    int i = q.front + 1;

    do {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while(i != (q.rear + 1) % q.size);
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
    display(q);
    return 0;
}