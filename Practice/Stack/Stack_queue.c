#include <stdio.h>
#include<stdlib.h>

typedef struct Queue {
    int size;
    int front;
    int rear;
    int *Q;
} Queue;

// Queue functions
void create (Queue *q,int s){
    q->size = s;
    q->Q = (int *)malloc(s * sizeof(int));
    q->front = q->rear = -1;
}

void enqueue (Queue*q, int x) {
    if (q->rear == q->size - 1) {
        printf("Queue is full\n");
    } else { // move rear and insert the element
        q->rear++;
        q->Q[q->rear] = x;
    }
    return;
}

int dequeue (Queue*q) {
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

// Stack implementation starts

typedef struct Stack {
    Queue q1, q2;
    int size;
} Stack;

Stack *s;

void createStack(int size) {
    s = (Stack*)malloc(sizeof(Stack));
    s->size = size;

    create(&s->q1, size);
    create(&s->q2, size);
}

void push (int x) {
    while (!isEmpty(s->q1)) // push all elements from q1 to q2
        enqueue(&s->q2, dequeue(&s->q1));

    enqueue(&s->q1, x); // push new element into q1

    while (!isEmpty(s->q2)) // move elements back to q1, this ll is done bcoz we can get top ele as front only (in queues).
        enqueue(&s->q1, dequeue(&s->q2));
}

int pop() {
    if (isEmpty(s->q1)) return -1;
    return dequeue(&s->q1);
}

int top() {
    if (isEmpty(s->q1)) return -1;
    return (s->q1.Q[s->q1.front + 1]);
}

int isEmptySt () {
    return isEmpty(s->q1);
}

int main () {
    int n;

    printf("Enter queue size: \n");
    scanf("%d", &n);
    createStack(n);

    push(2);
    push(4);
    push(6);
    printf("Popped value: %d\n", pop());
    printf("Top value: %d\n", top());
    printf("Popped value: %d\n", pop());
    printf("Top value: %d\n", top());
    printf("Popped value: %d\n", pop());
    printf("Top value: %d\n", top());
    printf("Popped value: %d\n", pop());
}