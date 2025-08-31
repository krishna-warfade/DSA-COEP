/*
Q1. Implement a menu-driven polynomial manipulation using a singly linked list for 
following operations: 
i.  Addition of polynomials 
ii. Subtraction of polynomials 

Q2. Implement a Singly Linked List and available list using array and perform the following 
Menu driven operations: 
i.   Insert an element at the beginning 
ii.  Traverse a list 
iii. Delete the first element 
*/

// Q2.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

Node* init(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertBeg (int val) {
    Node* node = init(val);
    node->next = head;
    head = node;
}

void Traverse () {
    Node* p = head;

    if (p == NULL) return;
    while (p)
        p = p->next;
    printf("Traversed successfully\n");
}

void DeleteBeg () {
    if (head == NULL) return;
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Node* p = head;
        head = head->next;
        free(p);
    }
}

void Display (Node* p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A) / sizeof(A[0]));
    Display(head);
    printf("\n");
    insertBeg(6);
    Display(head);
    printf("\n");
    Traverse();
    Display(head);
    printf("\n");
    DeleteBeg();
    Display(head);
    printf("\n");

    return 0;
}