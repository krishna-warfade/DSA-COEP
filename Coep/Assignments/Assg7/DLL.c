#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *prev, *next;
} Node;

Node* head = NULL;

void create (int A[], int n) {
    Node *newnode, *last;

    head = (Node*)malloc(sizeof(Node));
    head->prev = head->next = NULL;
    head->data = A[0];

    last = head;

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
    Node *p = head;
    Node* newnode;

    if (pos < 0 || pos > Count(p))
        return head;

    newnode = (Node*)malloc(sizeof(Node));
    newnode->data = x;
    if (pos == 0) {
        newnode->prev = NULL;
        newnode->next = head;
        if (head)
            head->prev = newnode;
        head = newnode;
    } else {
        for (int i = 1; i < pos; i++)
            p = p->next;
        newnode->next = p->next;
        newnode->prev = p;
        if (p->next)
            p->next->prev = newnode;
        p->next = newnode;
    }
    return head;
}

int Delete (Node *p, int pos) {
    int x = -1;

    if (pos < 0 || pos > Count(p))
        return x;
    if (pos == 1) {
        p = p->next;
        x = head->data;
        free(head);
        head = p;
        if (p)
            p->prev = NULL;
    } else {
        for (int i = 1; i < pos; i++)
            p = p->next;
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
    Node *curr = head, *temp = NULL;

    if (!head) return;

    while (curr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }
    if (temp)
        head = temp->prev;
}

int main () {
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A)/ sizeof(A[0]));
    Display(head);
    printf("The length of list is %d\n", Count(head));
    head = insert(20, 6); // insert end
    Display(head);
    Traverse(head);
    printf("The length of list is %d\n", Count(head));
    Search(head, 24);

    printf("Deleted the node with value %d\n", Delete(head, 4));
    Display(head);

    Reverse(head);
    Display(head);
    Reverse(head);
    Display(head);
    return 0;
}