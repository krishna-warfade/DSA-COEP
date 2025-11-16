#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node {
    char data[50];
    struct Node *next;
} Node;
Node *front = NULL;
Node *rear = NULL;

void push (char name[]){ //enqueue (insert at rear)
    Node *q = (Node*)malloc(sizeof(Node));

    if (q == NULL) {
        printf("Queue is Full\n");
        return;
    }
    strcpy(q->data, name);
    q->next = NULL;

    if (front == NULL)
        front = rear = q;
    else {
        rear->next = q;
        rear = q;
    }
    printf("Customer %s has joined the queue.\n", name);
    // q->data = x;
    // q->next = NULL;

}

void pop () { //dequeue (delete from front)
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    Node *p = front;

    printf("Booking processed for customer: %s\n", p->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(p);
}

void display () {
    if (front == NULL) {
        printf("No customers in the queue.\n");
        return;
    }

    Node *p = front;

    printf("Current Queue: ");
    while (p) {
        printf("%s", p->data);
        if (p->next != NULL)
            printf(" -> ");
        p = p->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char name[50];

    printf("--- Welcome to ABC Ticket Booking System ---\n");

    while(1) {
        printf("\n1. Add Customer\n");
        printf("2. Process Booking\n");
        printf("3. View Queue\n");
        printf("4. Exit\n");
        printf("Enter Your Choice (1 - 4): ");
        scanf("%d", &choice);
        getchar();

        switch(choice) {
            case 1:
                printf("Enter Customer Name: ");
                scanf("%s", name);
                push(name);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Thank you for using ABC Ticket Booking System!\n");
                exit(1);
            default:
                printf("Invalid choice! Please enter between 1 - 4.\n");
        }
    }
    return 0;
}