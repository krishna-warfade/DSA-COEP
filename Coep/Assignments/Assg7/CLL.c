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

void Traverse (Node *p) {
    if (p == NULL) return;
    do {
        p = p->next;
    } while(p != head);
    printf("Traversed Successfully\n");
}

int Count (Node *p) {
    int cnt = 0;

    if (p == NULL) return 0;
    do {
        p = p->next;
        cnt++;
    } while (p != head);
    return cnt;
}

void Search (Node *p, int x) {
    int found = 0;

    if (p == NULL) return;

    do {
        if (p->val == x) {
            found = 1;
            break;
        }
        p = p->next;
    } while (p != head);
    if (found) {
        printf("%d Found\n", x);
        return;
    } else {
        printf("%d Not Found\n", x);
    }
}

int Delete (Node *p, int idx) {
    Node* temp;
    int i, x;

    if (idx < 0 || idx > Count(head) || head == NULL)
        return -1;
    if (idx == 1) {
        while (p->next != head)
            p = p->next;
        x = head->val;

        if (head == p) {
            free(head);
            head = NULL;
        } else {
            p->next = head->next;
            free(head);
            head = p->next;
        }
    } else {
        for (int i = 1; i < idx - 1; i++)
            p = p->next;
        temp = p->next;
        p->next = temp->next;
        x = temp->val;
        free(temp);
    }
    return x;
}

void Reverse (Node *p) {
    if (head == NULL) return;
    Node *curr = head, *prev = NULL, *next = NULL;

    do {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    } while (curr != head);

    head->next = prev;
    head = prev;
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};

    create(A, sizeof(A)/ sizeof(A[0]));
    Display(head);
    printf("The length of list is %d\n", Count(head));
    head = insertBeg(10);
    Display(head);
    printf("The length of list is %d\n", Count(head));
    head = insert(20, 6); // insert end
    Display(head);
    Traverse(head);
    printf("The length of list is %d\n", Count(head));
    Search(head, 24);

    printf("Deleted the node with value %d\n", Delete(head, 7));
    Display(head);

    Reverse(head);
    Display(head);
    Reverse(head);
    Display(head);
    return 0;
}