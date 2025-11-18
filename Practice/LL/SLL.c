#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *first = NULL; // head
Node *second = NULL, *third = NULL, *last = NULL;

Node* init(int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = NULL;
    return newnode;
}

void create (int A[], int n) {
    int i;

    Node *newnode, *last; // since traversing till last

    // first = (Node*)malloc(sizeof(Node));
    // first->data = A[0];
    first = init(A[0]); // head
    last = first;

    for (i = 1; i < n; i++) {
        newnode = init(A[i]);

        last->next = newnode;
        last = newnode;
    }
}

void create2(int A[], int n) {
    int i;

    Node *newnode, *last; // since traversing till last

    second = init(A[0]); // head
    last = second;

    for (i = 1; i < n; i++) {
        newnode = init(A[i]);

        last->next = newnode;
        last = newnode;
    }
}

void insertBeg (int val) {
    Node* node = init(val);
    node->next = first;
    first = node;
}

void insertBeg2(Node** headRef, int val) {
    Node* newnode = init(val);

    newnode->next = *headRef; // link new node to current head(any list can be passed here), which is passed as argument
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
    Node* lst;

    if (first == NULL) {
        first = lst = newnode;
    } else {
        lst->next = newnode;
        lst = newnode;
    }
}

void insertSpec (int val, int idx) { // insert at a specified index, O(n)
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
    int j = 0;

    while (temp && j < idx - 1) { // reach node before reqd posn
        j++;
        temp = temp->next;
    }
    if (temp == NULL) {// temp = NULL, reached end of the list (during i.e idx > length of list)
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
    // empty list
    if (first == NULL) {
        first = newnode;
        return;
    }

    Node* fast = first; // moves and finds the position
    Node* slow = NULL; // keeps the pointer to previous node

    // If we use just 1 temp pointer, it would fail by going to the just next element after comparison of node's data and the value to be inserted. Hence we need to store the previously check data before jumping.
    while(fast && fast->data < val) { // fast jumps to just next greater element, i.e fast stops at first node whose data >= val
        slow = fast;
        fast = fast->next;
    }
    if (slow == NULL) { // insert at beginning, fast == first is wrong
        newnode->next = first;
        first = newnode;
    } else { // fast is not first, can insert node btwn fast and slow or at end
        newnode->next = fast; // OR slow->next
        slow->next = newnode;
    }
}

void DeleteBeg() {
    if (first == NULL) return;
    Node* temp = first;

    if (first->next == NULL) {
        free(first);
        first = NULL; // bcoz first will still point to freed memory
    } else {
        first = first->next; // OR temp->next
        free(temp);
    }
}

void DeleteEnd() {
    if (first == NULL) return;
    if (first->next == NULL) {
        free(first);
        first = NULL; // bcoz first will still point to freed memory
        return;
    }
    Node* temp = first;

    while (temp->next->next) 
        temp = temp->next;
    free(temp->next);
    temp->next = NULL; // bcoz temp will still point to freed memory
}

void DeletePos(int pos) {
    if (first == NULL) return;
    if (pos == 1) {
        DeleteBeg();
        return;
    }

    Node* slow = NULL;
    Node* fast = first;
    int i = 0;

    while (fast && i < pos - 1) {
        slow = fast;
        fast = fast->next;
        i++;
    }
    if (fast == NULL) return; // pos is out of bound
    slow->next = fast->next;
    free(fast);
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

void BinarySearch (Node *p, int val) {
    int found = 0, l = 0, h = RCount(p) - 1;

    if (p == NULL) return;


    while (l <= h) {
        int mid = (l + h) / 2;

        Node* temp = p; // to go till mid node
        for (int i = 0; i < mid && temp; i++) {
            temp = temp->next;
        }
        if (!temp) break;

        if (temp->data == val){
            found = 1;
            break;
        }
        else if (temp->data < val) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }

    }
    if(found)
        printf("%d Found in the list\n", val);
    else 
        printf("%d Not Found in the list\n", val);

}

bool isSorted () {
    Node* fast = first;
    Node* slow = NULL;
    // OR can store prev node's value in a variable x and compare with a pointer - single ptr needed

    // int x;

    // while (fast->next) {
    //     x = fast->data;
    //     fast = fast->next;
    //     if (x > fast->data)
    //         return false;
    // }

    while (fast->next) {
        slow = fast;
        fast = fast->next;
        if (slow->data > fast->data)
            return false;
    }
    return true;
}

Node* rmDupS () {
    Node* temp = first;

    if (temp == NULL || temp->next == NULL) return first;

    while (temp && temp->next) { //checking temp bcoz in the if part temp can point to null
        if (temp->data == (temp->next)->data)
        {
            Node* dup = temp->next;
            temp->next = dup->next;
            free(dup); //protn from mem leak
        }
        else temp = temp->next;
    }
    return first;
}

Node* rmDupS2 () {
    if (first == NULL || first->next == NULL) return first;

    Node* slow = first;
    Node* fast = first->next; // first->next

    while (fast) {
        if (slow->data == fast->data) {
            Node* dup = fast;
            slow->next = fast->next; // dup->next
            fast = slow->next;
            free(dup);
        }
        else {
            slow = fast;
            fast = fast->next;
        }
    }
    return first;
}

void Reverse2 () { //reversing data using array
    Node* temp = first;
    int *arr = (int*)malloc(100 * sizeof(int));
    int i = 0;

    while (temp) {
        arr[i++] = temp->data;
        temp = temp->next;
    }
    i--; // last index
    temp = first;
    while (i >= 0) {
        temp->data = arr[i--];
        temp = temp->next;
    }
    free(arr);
}

void Reverse () { // using sliding pointers, fibonacci logic
    Node* prev = NULL;
    Node* curr = NULL;
    Node* nxt = first;

    while (nxt) {
        prev = curr;
        curr = nxt;
        nxt = nxt->next;
        curr->next = prev;
    }
    first = curr;
}

/*
leetcode
struct ListNode* reverse (struct ListNode* l) {
    struct ListNode* prev = NULL;
    struct ListNode* curr = NULL;
    struct ListNode* n = l;

    while (n) {
        prev = curr;
        curr = n;
        n = n->next;

        curr->next = prev;
    }
    return curr;
}
*/

void ReverseRec (Node* q, Node* p) {
    if (p) {
        ReverseRec(p, p->next);
        p->next = q; // recursive call pointing to previous
    }
    else
        first = q;
}

void Concat(Node*p, Node* q) {
    // third = p;
    while(p->next) 
        p = p->next;
    p->next = q;
    q = NULL; // second pointer removed
}

void Merge (Node* p, Node* q) { // combining 2 sorted list into single sorted list
    if (p == NULL) {
        third = q;
        return;
    }
    if (q == NULL) {
        third = p;
        return;
    }
    if (p->data <= q->data) { // init 3rd- starting point of merged list & init last ptr as well
        third = last = p;
        p = p->next;
    } else {
        third = last = q;
        q = q->next;
    }
    last->next = NULL;

    while (p && q) {
        if (p->data <= q->data) {
            last->next = p;
            last = p;
            p = p->next;
        } else {
            last->next = q;
            last = q;
            q = q->next;
        }
        last->next = NULL;
    }
    // attach remaining nodes
    if (p) last->next = p;
    if (q) last->next = q;
}

void CheckLoop (Node* p) {
    if (!p) {
        printf("Cycle Not Found\n");
        return;
    }

    Node* slow = p;
    Node* fast = p;

    do {
        slow = slow->next;

        if(fast) fast = fast->next;
        if(fast) fast = fast->next;
    } while (slow && fast && slow != fast);
    
    if (slow == fast)
        printf("Cycle Found\n");
    else
        ("Cycle Not Found\n");

    // while (p->next != p && p->next) {
    //     p = p->next;
    // }
    // if(p->next == p) {
    //     printf("Cycle Found\n");
    //     return;
    // }
    // printf("Cycle Not Found\n");
}

int main()
{
    int A[] = {1, 3, 5, 7, 9};
    int B[] = {2, 4, 6};

    create(A, sizeof(A) / sizeof(A[0]));
    create2(B, sizeof(B) / sizeof(B[0]));

    // insertBeg(15);
    // insertBeg2(&first, 25);
    // insertSpec(65, 6);
    // insertEnd(24);
    RDisplay(first);
    printf("\n");
    // DisplayMax(first);
    // DisplayMin(first);
    // LinearSearch(first, 24);
    // BinarySearch(first, 3);
    // printf("Length is: %d\n", RCount(first));
    // printf("Sum is: %d\n", RSum(first));
    // insertSorted(5);
    // printf("\nAfter insertSorted\n");
    // while (first) {
    //     DeleteBeg();
    //     RDisplay(first);
    //     printf("\n");
    // }
    // DeleteEnd();
    // DeletePos(5);
    // if (isSorted()) printf("List is sorted");
    // else printf("List is Unsorted");
    // rmDupS2 ();
    // Reverse();
    // ReverseRec(NULL, first);
    // Concat(first, second);
    // RDisplay(first);
    // printf("\n")
    // RDisplay(second);
    // printf("\n");
    // Merge(first, second);
    // RDisplay(third);
    // printf("\n");
    CheckLoop(first);
    
    return 0;
}