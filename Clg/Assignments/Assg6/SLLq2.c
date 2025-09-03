/*
Q2. Implement a Singly Linked List and available list using array and perform the following 
Menu driven operations: 
i.   Insert an element at the beginning 
ii.  Traverse a list 
iii. Delete the first element 
*/

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

void create (int A[], int n) {
    int i;

    Node *newnode, *last; //since traversing till last

    head = init(A[0]);
    last = head;

    for (i = 1; i < n; i++) {
        newnode = init(A[i]);

        last->next = newnode;
        last = newnode;
    }
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
    int val, choice;

    create(A, sizeof(A) / sizeof(A[0]));

    while (1) {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Traverse List\n");
        printf("4. Delete from Beginning\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                Display(head);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                insertBeg(val);
                break;
            case 3:
                Traverse();
                break;
            case 4:
                DeleteBeg();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}