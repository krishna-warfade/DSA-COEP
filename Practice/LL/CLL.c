#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head = NULL;
Node* last = NULL;

Node* init (int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->val = data;
    newnode->next = head; // CIRCULAR
    return newnode;
}

void create (int A[], int n) {
    // head = init(A[0]);
    head = (Node*)malloc(sizeof(Node));
    head->val = A[0];
    head->next = head; // Circular

    last = head;

    for (int i = 1; i < n; i++) {
        Node* newnode = init(A[i]);

        last->next = newnode;
        last = newnode;
    }
    last->next = head;
}

Node* insertBeg(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = data;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
        last = head;
    } else {
        newnode->next = head;
        last->next = newnode;
        head = newnode;
    }
    return head;
}

int length() {
    Node* temp = head;
    int len = 0;

    do {
        len++;
        temp = temp->next;
    } while (temp != head);
    return len;
}

Node* insert(int data, int idx) {
    Node* temp = head;

    if (idx == 1) {
        Node* newnode = init(data);
        if (head == NULL) {
            head = newnode;
            head->next = newnode;
        } else {
            while (temp->next != head)
                temp = temp->next;
            temp->next = newnode;
            newnode->next = head;
            head = newnode;
        }
    } else {
        if (idx < 0 || idx > length())
            return NULL;
        for (int i = 0; i < idx - 1; i++)
            temp = temp->next;
        Node* newnode = init(data);

        newnode->next = temp->next;
        temp->next = newnode;
        // while (i < idx - 1) {
        //     temp = temp->next;
        //     i++;
        // }
    }

    return head;
}

void Display (Node *p) {
    if (p == NULL) return;
    do {
        printf("%d ", p->val);
        p = p->next;
    } while(p != head);
    printf("\n");
}

void RDisplay (Node *p) {
    // flag tells how many cycles

    static int flag = 0; // limited to a function
    if (p != head || flag == 0) {
        flag = 1;
        printf("%d ", p->val);
        RDisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A)/ sizeof(A[0]));
    Display(head);
    head = insertBeg(10);
    head = insert(20, 1);
    RDisplay(head);
    return 0;
}