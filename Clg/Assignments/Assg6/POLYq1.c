/*
Q1. Implement a menu-driven polynomial manipulation using a singly linked list for 
following operations: 
i.  Addition of polynomials 
ii. Subtraction of polynomials
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int coeff;
    int pwr;
    struct Node* next;
}Node;

Node* head;

Node* init (int coeff, int pwr) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->coeff = coeff;
    newnode->pwr = pwr;
    newnode->next = NULL;
    return newnode;
}

void insert(Node** head, int coeff, int pwr) {
    Node* newnode = init(coeff, pwr);
    if (*head == NULL)
        *head = newnode;
    else {
        Node* temp = *head;
        while(temp->next)
            temp = temp->next;
        temp->next = newnode;
    }
}

Node* create() {
    head = NULL;
    int n, coeff, pwr;

    printf("Enter no. of polynomials: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter coeff and pwr: ");
        scanf("%d%d", &coeff, &pwr);
        insert(&head, coeff, pwr);
    }
    return head;
}

Node* add(Node* p, Node* q) {
    Node* res = NULL;

    while (p && q) {
        if (p->pwr > q->pwr) {
            insert(&res, p->coeff, p->pwr);
            p = p->next;
        } else if (p->pwr < q->pwr) {
            insert(&res, q->coeff, q->pwr);
            q = q->next;
        } else {// both have same powers
            insert(&res, p->coeff + q->coeff, p->pwr);
            p = p->next;
            q = q->next;
        }
    }
    while (p) {
        insert(&res, p->coeff, p->pwr);
        p = p->next;
    }
    while (q) {
        insert(&res, q->coeff, q->pwr);
        q = q->next;
    }
    return res;
}

Node* sub(Node* p, Node* q) {
    Node* res = NULL;

    while (p && q) {
        if (p->pwr > q->pwr) {
            insert(&res, p->coeff, p->pwr);
            p = p->next;
        } else if (p->pwr < q->pwr) {
            insert(&res, -q->coeff, q->pwr);
            q = q->next;
        } else {// both have same powers
            insert(&res, p->coeff - q->coeff, p->pwr);
            p = p->next;
            q = q->next;
        }
    }
    while (p) {
        insert(&res, p->coeff, p->pwr);
        p = p->next;
    }
    while (q) {
        insert(&res, -q->coeff, q->pwr);
        q = q->next;
    }
    return res;
}

void display(Node* p) {
    if(p == NULL) {
        printf("0\n");
        return;
    }
    Node* temp = p;
    while(temp) {
        printf("%dx^%d", temp->coeff, temp->pwr);

        if (temp->next && temp->next->coeff == 0)
            printf(" + ");
        else if (temp->next)
            printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Node *poly1 = NULL, *poly2 = NULL, *res = NULL;
    int choice;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Enter first polynomial\n");
        printf("2. Enter second polynomial\n");
        printf("3. Display polynomials\n");
        printf("4. Add polynomials\n");
        printf("5. Subtract polynomials (poly1 - poly2)\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                poly1 = create();
                break;
            case 2:
                poly2 = create();
                break;
            case 3:
                printf("Poly1: ");
                display(poly1);
                printf("Poly2: ");
                display(poly2);
                break;
            case 4:
                res = add(poly1, poly2);
                printf("Addition Result: ");
                display(res);
                break;
            case 5:
                res = sub(poly1, poly2);
                printf("Subtraction Result: ");
                display(res);
                break;
            case 6:
                exit(1);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}