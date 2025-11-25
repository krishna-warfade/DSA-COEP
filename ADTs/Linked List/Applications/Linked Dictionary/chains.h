#include<stdio.h>
#include<stdlib.h>
#ifndef chains_h
#define chains_h

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* init(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertSorted (Node **first, int val) {
    Node* newnode = init(val);

    if (*first == NULL) {
        *first = newnode;
        return;
    }

    Node* fast = *first;
    Node* slow;

    while(fast && fast->data < val) { 
        slow = fast;
        fast = fast->next;
    }
    if (!slow) {
        newnode->next = *first;
        *first = newnode;
    } else {
        newnode->next = fast;
        slow->next = newnode;
    }
}

Node* LinearSearch (Node *p, int val) {
    while (p) {
        if (p->data == val) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void Display (Node* p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

#endif