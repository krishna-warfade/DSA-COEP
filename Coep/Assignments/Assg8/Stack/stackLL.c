#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// USING LL

typedef struct Node { // stack
    int data;
    struct Node* next;
}Node;

Node *top = NULL;

void push (int x) { // insert
    Node *newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) {
        return;
    }
    else { 
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }
}

int pop () { // delete
    int x = -1;

    if (top == NULL)
        return -1;
    else {
        x = top->data;
        top = top->next;
    }
    return x;
}

void traverse (Node *p) {
    if (!p)
        return;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    push(2);
    push(4);

    printf("TOP to BOTTOM : ");
    traverse(top);

    printf("TOPMOST ELEMENT : %d\n", pop());

    printf("TOP to BOTTOM : ");
    traverse(top);
}