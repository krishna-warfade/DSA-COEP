#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* head = NULL;

Node* insertBeg(int data) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->val = data;

    if (head == NULL) {
        newnode->next = newnode;
        head = newnode;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = newnode;
        newnode->next = head;
        head = newnode;
    }
    return head;
}

void Display () {
    Node* p = head;

    do {
        printf("%d ", p->val);
        p = p->next;
    } while(p != head);
    printf("\n");
}

int main()
{
    head = insertBeg(10);
    head = insertBeg(20);
    head = insertBeg(30);
    Display();
    return 0;
}