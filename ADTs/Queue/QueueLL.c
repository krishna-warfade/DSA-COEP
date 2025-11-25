#include<stdio.h>
#include<stdlib.h>

typedef struct QNode {
    int data;
    struct QNode *next;
} QNode;

QNode *front = NULL, *rear = NULL;

void enqueue(int x) {
    QNode *q;
    q = (QNode*)malloc(sizeof(QNode));
    if(q==NULL){
        printf("Queue is Full");
    }else{
        q->data=x;
        q->next=NULL;
        if(front==NULL){
            front = rear = q;
        }
        else {
        rear->next=q;
        rear = q;
        }
    }
    return;

}

int dequeue() {
    int x = -1;

    if(front == NULL){
        printf("Queue is empty");
    }else{
        QNode *p;
        p = front;
        front=front->next;
        x = p->data;
        free(p);
    }
    return x;
}

void display() {
    QNode *p;
    p = front;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int isEmpty () {
    return front == NULL;
}

int main() {
    enqueue(3);
    enqueue(4);
    enqueue(6);
 
    display();
}