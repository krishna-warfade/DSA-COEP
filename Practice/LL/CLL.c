#include <stdio.h>
#include <stdlib.h>

// Delete remaining

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* first = NULL;
Node* last = NULL;

// Node* init (int x) {
//     Node* newnode = (Node*)malloc(sizeof(Node));

//     newnode->data = x;
//     newnode->next = first; // CIRCULAR
//     return newnode;
// }

void create (int A[], int n) {
    // first = init(A[0]);
    first = (Node*)malloc(sizeof(Node));
    first->data = A[0];
    first->next = first; // Circular
    last = first;

    for (int i = 1; i < n; i++) {
        Node* newnode = (Node*)malloc(sizeof(Node)); // init(A[i])
        
        newnode->data = A[i];
        newnode->next = last->next; // last->next will always point to first

        last->next = newnode;
        last = newnode;
    }
    // last->next = first; redundant as last->next will always point to first
}

// Node* insertBeg(int x) {
//     Node* newnode = (Node*)malloc(sizeof(Node));
//     newnode->data = x;

//     if (first == NULL) {
//         newnode->next = newnode;
//         first = newnode;
//         last = first;
//     } else {
//         newnode->next = first;
//         last->next = newnode;
//         first = newnode;
//     }
//     return first;
// }

int length() {
    Node* temp = first;
    int len = 0;

    do {
        len++;
        temp = temp->next;
    } while (temp != first);
    return len;
}

Node* insert(int x, int pos) {
    Node* temp = first;

    if (pos < 1 || pos > length())
            return NULL;
    if (pos == 1) { 
        Node* newnode = (Node*)malloc(sizeof(Node)); // init(x);

        newnode->data = x;
        if (first == NULL) { // empty list
            first = newnode;
            newnode->next = newnode; // first
        } else { // finding the last node, since insert at first = insert at last (#circular)
            while (temp->next != first) {
                temp = temp->next;
            }
            newnode->next = temp->next; // first
            temp->next = newnode;
            first = newnode;
        }
    } else {
        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;
        Node* newnode = (Node*)malloc(sizeof(Node)); // init(x);
        newnode->data = x;

        newnode->next = temp->next;
        temp->next = newnode;
    }
    return first;
}

int delete (int pos) {
    int x = -1;
    
    if (first == NULL)
        return x;
    Node* temp = first;

    // delete first node
    if (pos == 1) {
        while (temp->next != first)
            temp = temp->next; // to delete first i.e to delete the last, go till end
        if (temp == first) { // only one node
            x = first->data;
            free(first);
            first = NULL;
        } else { // more than one node
            Node *del = first;
            x = del->data;

            temp->next = first->next; // last->next = new head
            first = first->next;
            free(del);
        }
    } else {
        Node *slow = NULL;
        // move to (pos - 1)th node
        for (int i = 0; i < pos - 2; i++) {
            temp = temp->next;
            if (temp->next == first) // out of bound
                return -1;
        }
        slow = temp->next; // node to be deleted

        temp->next = slow->next;

        x = slow->data;
        free(slow);
    }
    return x;
}

void Display (Node *p) {
    if (p == NULL) return;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while(p != first);
    printf("\n");
}

void RDisplay (Node *p) {
    // flag tells how many cycles

    static int flag = 0; // limited to a function
    if (p != first || flag == 0) {
        flag = 1;
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    flag = 0;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A)/ sizeof(A[0]));
    Display(first);
    first = insert(10, 1);
    Display(first);
    first = insert(20, 6);
    RDisplay(first);
    printf("\n");
    printf("Deleted node has the value: %d\n", delete(2));
    RDisplay(first);
    return 0;
}