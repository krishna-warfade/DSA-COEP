#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *first; //head

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

void insertBeg2(Node** headRef, int val) {
    Node* newnode = init(val);

    newnode->next = *headRef; // link new node to current head
    *headRef = newnode;       // update head itself
}

void insertEnd (int val) {
    Node* node = init(val);
    
    if (first == NULL) {
        first = node;
        return;
    }

    Node* temp = first;

    while (temp->next)
        temp = temp->next;
    temp->next = node;
}

void insertEnd2 (int x) {
    Node* newnode = init(x);
    Node* last;

    if (first == NULL) {
        first = last = newnode;
    } else {
        last->next = newnode;
        last = newnode;
    }
}

void insertSpec (int val, int idx) {
    if (idx < 0) {
        printf("Invalid index\n");
        return;
    }
    if (idx == 0) {
        insertBeg(val);
        return;
    }
    Node* newnode = init(val);
    Node* temp = first;
    int j = 0; //int len = 0;

    while (temp && j < idx - 1) {
        j++;
        temp = temp->next; //reached the inserting position
    }
    if (temp == NULL) //temp = NULL during i.e idx > length of list
    {
        printf("Invalid index\n");
        free(newnode);
        return;
    }
    newnode->next = temp->next;
    temp->next = newnode;

    // temp = first;
    // if (idx > len) {
    //     printf("Invalid index\n");
    //     return;
    // }
    // while (j != idx - 1) {
    //     temp = temp->next;
    //     j++;
    // }
    
}

void insertSorted (int val) {
    Node* newnode = init(val);
    if (first == NULL) first = newnode;
    Node* slow = NULL;
    Node* fast = first;

    while(fast && fast->data < val) { // fast jumps to just next greater element
        slow = fast;
        fast = fast->next;
    }
    if (fast == first) {
        newnode->next = first;
        first = newnode;
    } else { //fast is not first, can insert node btwn fast and slow
        newnode->next = fast;
        slow->next = newnode;
    }
}

void DeleteBeg() {
    if (first == NULL) return;
    Node* temp = first;

    if (first->next == NULL) {
        free(first);
        first = NULL;
    } else {
        first = first->next;
        free(temp);
    }
}

void DeleteEnd() {
    if (first == NULL) return;
    Node* temp = first;

    if (first->next == NULL) {
        free(first);
        first = NULL;
    } else {
        while (temp->next->next) {
            temp = temp->next;
        }
        free(temp->next);
        temp->next = NULL;
    }
}

void create (int A[], int n) {
    int i;

    Node *newnode, *last; //since traversing till last

    // first = (Node*)malloc(sizeof(Node));
    // first->data = A[0];
    first = init(A[0]);
    last = first;

    for (i = 1; i < n; i++) {
        newnode = init(A[i]);

        last->next = newnode;
        last = newnode;
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

    while (q && !found) {
        if (q->data == val)
            found = 1;
        q = q->next;
    }
    if(found)
        printf("%d Found in the list\n", val);
    else 
        printf("%d Not Found in the list\n", val);
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

int RCount (Node* p) {
    if (p == NULL) return 0;
    return RCount(p->next) + 1;
}

int RSum (Node* p) {
    if (p == 0) return 0;
    return RSum(p->next) + p->data;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A) / sizeof(A[0]));

    // insertBeg(15);
    // insertBeg2(&first, 25);
    // insertSpec(65, 6);
    // insertEnd(24);
    RDisplay(first);
    printf("\n");
    // DisplayMax(first);
    // DisplayMin(first);
    // LinearSearch(first, 24);
    // printf("Length is: %d\n", RCount(first));
    // printf("Sum is: %d\n", RSum(first));
    // insertSorted(6);
    // printf("\nAfter insertSorted\n");
    // RDisplay(first);
    // printf("\n");
    // while (first) {
    //     DeleteBeg();
    //     RDisplay(first);
    //     printf("\n");
    // }
    // DeleteEnd();

    RDisplay(first);
    printf("\n");
    return 0;
}