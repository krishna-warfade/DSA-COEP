#include <stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void enqueue(struct Queue*q,int x){
    if(q->rear==q->size-1){
        printf("Queue is full\n");
    }else{
        q->rear++;
        q->Q[q->rear] = x;
    }
    return;
}

int dequeue(struct Queue*q){
    int x = -1;
    if(q->rear==q->front){
        printf("Queue is empty\n");
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    for(int i = q.front+1;i<=q.rear;i++){
        printf("%d ",q.Q[i]);
    }
    printf("\n");
}
void create(struct Queue *q,int s){
    q->size = s;
    q->front=q->rear=-1;
    q->Q = (int *)malloc(s*sizeof(int));
}
int main(){
    struct Queue q;
    create(&q,5);
    enqueue(&q,2);
    enqueue(&q,3);
    enqueue(&q,4);
    dequeue(&q);
    display(q);
    return 0;
}