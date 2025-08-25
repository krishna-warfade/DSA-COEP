/*Menu driven 1a,1b,1b,2,3a,3b,3c,4,5,6*/
/*insert - 3 pos, traverse, delete - 3 pos, count, search, reverse*/

#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* head;

Node* init(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void InsertBeg (int val) {
    Node* node = init(val);

    if (head == NULL) head = node;
    else {
        node->next = head;
        head = node;
    }
}

void InsertEnd (int val) {
    Node* node = init(val);
    Node* temp = head;

    while (temp->next) temp = temp->next;
    temp->next = node;
}

void InsertPos (int val, int pos) {
    if (pos == 1 ) {
        InsertBeg(val);
        return;
    }

    Node* node = init(val);
    Node* p = head;

    int i = 1;

    while (p && i < pos - 1)
    {
        p = p->next;
        i++;
    }
    if (pos > i + 1) {
        printf("Invalid Position\n");
        return;
    }
    node->next = p->next;
    p->next = node;
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

void DeleteEnd () {
    if (head == NULL) return;
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        Node* q = NULL;
        Node* p = head;

        while (p->next) {
            q = p;
            p = p->next;
        }
        q->next = NULL;
        free(p);
    }
}

void DeletePos (int pos) {
    if (head == NULL) return;
    if (pos == 1) {
        DeleteBeg();
        return;
    }
    Node* q = NULL;
    Node* p = head;

    int i = 1;

    while (p && i < pos) {
        q = p;
        p = p->next;
        i++;
    }
    if (p == NULL) {
        printf("Invalid position to delete node\n");
        return;
    }
    q->next = p->next;
    free(p);
}

int Count(Node *p) {
    int len = 0;

    if (p == NULL) return 0;
    while (p)
    {
        p = p->next;
        len++;
    }
    
    return len;
}

void Search (int val) {
    Node* p = head;

    while(p) {
        if (p->data == val) {
            printf("%d found in the list\n", val);
            return;
        }
        p = p->next;
    }
    printf("%d not found in the list\n", val);
}

void Reverse () {
    Node* prev = NULL;
    Node* curr = NULL;
    Node* n = head;

    while (n) {
        prev = curr;
        curr = n;
        n = n->next;
        curr->next = prev;
    }
    head = curr;
}

void DisplayHead () {
    Node* p = head;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int main() {
    InsertBeg(10);
    InsertBeg(20);
    InsertBeg(30);
    InsertEnd(40);
    InsertEnd(50);
    InsertEnd(50);
    InsertEnd(890);
    InsertPos(99, 6);
    Traverse();
    DisplayHead();
    int len = Count(head);

    printf("Length of List is : %d\n", len);
    DeleteBeg();
    DisplayHead();
    len = Count(head);
    printf("Length of List is : %d\n", len);
    DeleteEnd();
    DisplayHead();
    int newlen = Count(head);

    printf("Now, length of List is : %d\n", newlen );

    DeletePos(2);
    DisplayHead();
    newlen = Count(head);
    printf("length of List is : %d\n", newlen );

    // Search(25);
    Search(20);

    Reverse();
    printf("Head is Reversed !!\n");
    DisplayHead();

    return 0;
}