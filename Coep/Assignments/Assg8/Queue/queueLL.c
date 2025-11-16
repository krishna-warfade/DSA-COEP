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

void push (int x) { //enqueue (insert at rear)
    Node *q = (Node*)malloc(sizeof(Node));

    if (q == NULL) {
        printf("Queue is Full\n");
    } else {
        q->data = x;
        q->next = NULL;
        if (front == NULL)
            front = rear = q;
        else {
            rear->next = q;
            rear = q;
        }
    }
    return;
}

int pop () { //dequeue (delete from front)
    int x = -1;

    if (front == NULL) {
        printf("Queue is Empty\n");
        return x;
    } else {
        Node *p;
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display () {
    Node *p;
    p = front;

    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main () {
    display();
    push(10);
    display();
    push(20);
    display();
    push(30);
    display();
    printf("Popped value: %d\n", pop());
    push(40);
    display();
    return 0;
}