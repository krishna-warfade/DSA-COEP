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

int Count() {
    int len = 0;

    Node *p = head;
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
    int code, val, pos, len;
    char subcode;

    while (1) {
        printf("\n-----------------------\n");
        printf("MENU:\n");
        printf("1a- Insert at Beginning\n1b- Insert at End\n1c- Insert at Position\n");
        printf("2- Traverse\n");
        printf("3a- Delete at Beginning\n3b- Delete at End\n3c- Delete at Position\n");
        printf("4- Count elements\n");
        printf("5- Search element\n");
        printf("6- Reverse List\n");
        printf("0- Exit\n");

        printf("Enter Code: ");
        scanf("%d", &code);
        if (code == 0) break;
        switch (code) {
            case 1 :
                printf("Enter subcode (a/b/c): ");
                scanf(" %c", &subcode);
                if (subcode == 'a') {
                    printf("Enter value to be inserted at Beginning: ");
                    scanf("%d", &val);
                    InsertBeg(val);
                } else if(subcode == 'b') {
                    printf("Enter value to be inserted at End: ");
                    scanf("%d", &val);
                    InsertEnd(val);
                } else if (subcode == 'c') {
                    printf("Enter value & position: ");
                    scanf("%d%d", &val, &pos);
                    InsertPos(val, pos);
                } else {
                    printf("Invalid Subcode\n");
                }
                printf("List is: ");
                DisplayHead();
                break;
            case 2 :
                Traverse();
                printf("List is: ");
                DisplayHead();
                break;
            case 3 :
                printf("Enter subcode (a/b/c): ");
                scanf(" %c", &subcode);
                if (subcode == 'a') {
                    printf("Element is Deleted at Beginning\n");
                    DeleteBeg();
                } else if(subcode == 'b') {
                    printf("Element is Deleted at End\n");
                    DeleteEnd();
                } else if (subcode == 'c') {
                    printf("Enter position of element to be Deleted: ");
                    scanf("%d", &pos);
                    DeletePos(pos);
                } else {
                    printf("Invalid Subcode\n");
                }
                printf("List is: ");
                DisplayHead();
                break;
            case 4 :
                len = Count();
                printf("List is: ");
                DisplayHead();
                printf("Length of List is : %d\n", len);
                break;
            case 5 :
                printf("Enter the element to search: ");
                scanf("%d", &val);
                Search(val);
                break;
            case 6 :
                Reverse();
                printf("List (Head) is Reversed !!\n");
                printf("List is: ");
                DisplayHead();
                break;
            default :
                printf("Enter a valid Code\n");
                break;
            
        }
    }
    return 0;
}