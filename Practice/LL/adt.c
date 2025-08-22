#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *first;

Node* init(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void insertBeg (int val) {
    Node* node = init(val);
    node->next = first;
    first = node;
}

void create (int A[], int n) {
    int i;

    Node *t, *last; //since traversing till last

    // first = (Node*)malloc(sizeof(Node));
    // first->data = A[0];
    first = init(A[0]);
    last = first;

    for (i = 1; i < n; i++) {
        t = init(A[i]);

        last->next = t;
        last = t;
    }
}

void Display (Node* p) {
    while(p) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void RDisplay (Node* p) {
    if (p == 0) return;
    if (p) {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}

void DisplayMax (Node *p) {
    Node *q = p->next;
    int max = p->data;

    while (q) {
        if (q->data > max)
            max = q->data;
        q = q->next;
    }
    printf("\nHighest Element: %d\n", max);
}

void LinearSearch (Node *p, int val) {
    Node *q = p;
    int found = 0;

    while (q) {
        if (q->data == val)
            found = 1;
        q = q->next;
    }
    if(found)
        printf("%d Found\n", val);
    else 
        printf("%d Not Found\n", val);
}

void DisplayMin (Node *p) {
    Node *q = p->next;
    int min = p->data;

    while (q) {
        if (q->data < min)
            min = q->data;
        q = q->next;
    }
    printf("Lowest Element: %d\n", min);
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A) / sizeof(A[0]));

    insertBeg(15);

    RDisplay(first);

    DisplayMax(first);

    DisplayMin(first);

    LinearSearch(first, 8);

    return 0;
}