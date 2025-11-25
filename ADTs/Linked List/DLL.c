#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
} Node;

Node* first = NULL;

void create (int A[], int n) {
    Node *newnode, *last;

    first = (Node*)malloc(sizeof(Node));
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;

    last = first;

    for (int i = 1; i < n; i++) {
        newnode = (Node *)malloc(sizeof(Node));
        newnode->data = A[i];
        newnode->next = last->next;
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}

int Count (Node *p) {
    int cnt = 0;

    if (p == NULL) return 0;
    while (p) {
        p = p->next;
        cnt++;
    }
    return cnt;
}

void Display(Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void Traverse(Node *p)
{
    while (p)
    {
        p = p->next;
    }
    printf("Traversed Successfully\n");
}

Node* insert (int x, int pos) {
    if (pos < 0 || pos > Count(first))
        return first;
    Node *p = first;
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;

    if (pos == 0) {
        newnode->prev = NULL;
        newnode->next = first;
        if (first)
            first->prev = newnode;
        first = newnode;
    } else {
        for (int i = 0; i < pos - 1 && p; i++) // reach a node before inserting position
            p = p->next;
        newnode->next = p->next;
        newnode->prev = p;
        if (p->next) // crucial
            p->next->prev = newnode;
        p->next = newnode;
    }
    return first;
}

int delete (Node *p, int pos) {
    int x = -1;

    if (first == NULL || pos < 1 || pos > Count(p))
        return x;
    if (pos == 0) {
        first = first->next;
        x = first->data;
        if (first)
            first->prev = NULL;
        free(p);
    } else {
        for (int i = 0; i < pos; i++) // crucial, xero indexing
            p = p->next; // p now points to the node to be deleted
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
    }
    return x;
}

void Search (Node *p, int x) {
    int found = 0;

    if (p == NULL) return;

    while (p) {
        if (p->data == x) {
            found = 1;
            break;
        }
        p = p->next;
    }
    if (found) {
        printf("%d Found\n", x);
        return;
    } else {
        printf("%d Not Found\n", x);
    }
}

void Reverse () {
    if (!first) return;
    Node *curr = first, *temp = NULL;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if (temp)
        first = temp->prev;
}

int main () {
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A)/ sizeof(A[0]));
    Display(first);
    printf("The length of list is %d\n", Count(first));
    first = insert(24, 3);
    Display(first);
    Traverse(first);
    printf("The length of list is %d\n", Count(first));
    Search(first, 24);

    printf("Deleted the node with value %d\n", delete(first, 4));
    Display(first);

    Reverse(first);
    Display(first);
    Reverse(first);
    Display(first);
    return 0;
}