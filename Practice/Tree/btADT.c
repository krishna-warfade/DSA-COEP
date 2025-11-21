#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node *root = NULL;

// Stack operations start

typedef struct StNode {
    struct Node *treeNode;
    struct StNode* next;
} StNode;

// We need distinct pointers for the generic stack (Pre/In) and the two stacks for Postorder
StNode *top = NULL;
StNode *top1 = NULL;
StNode *top2 = NULL;

// --- GENERIC STACK (For Preorder/Inorder) ---

void push (Node *t) { // insert
    StNode *newStNode = (StNode*)malloc(sizeof(StNode));

    if (newStNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    else { 
        newStNode->treeNode = t; // store the address
        newStNode->next = top;
        top = newStNode;
    }
}

Node* pop () { // returns a node pointer
    Node *t = NULL;

    if (top == NULL)
        return NULL;
    else {
        StNode *temp = top;
        t = top->treeNode;
        top = top->next;
        free(temp);
    }
    return t;
}

int isEmptyStack () {
    return top == NULL;
}

// --- STACK 1 (For Postorder) ---

void push1 (Node *t) { // insert
    StNode *newStNode = (StNode*)malloc(sizeof(StNode));

    if (newStNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    else { 
        newStNode->treeNode = t; // store the address
        newStNode->next = top1;
        top1 = newStNode;
    }
}

Node* pop1 () { // returns a node pointer
    Node *t = NULL;

    if (top1 == NULL)
        return NULL;
    else {
        StNode *temp = top1;
        t = top1->treeNode;
        top1 = top1->next;
        free(temp);
    }
    return t;
}

int isEmptyStack1 () {
    return top1 == NULL;
}

// --- STACK 2 (For Postorder) ---

void push2 (Node *t) { // insert
    StNode *newStNode = (StNode*)malloc(sizeof(StNode));

    if (newStNode == NULL) {
        printf("Stack Overflow\n");
        return;
    }
    else { 
        newStNode->treeNode = t; // store the address
        newStNode->next = top2;
        top2 = newStNode;
    }
}

Node* pop2 () { // returns a node pointer
    Node *t = NULL;

    if (top2 == NULL)
        return NULL;
    else {
        StNode *temp = top2;
        t = top2->treeNode;
        top2 = top2->next;
        free(temp);
    }
    return t;
}

int isEmptyStack2 () {
    return top2 == NULL;
}

// Stack operations end

int height (Node* root);

Node *insert (int x, Node *t) {
    Node *p, *q;

    Node *root = t;
    p = NULL;
    if (!t) { // inserting/initializing as root
        q = (Node*)malloc(sizeof(Node));
        q->data = x;
        q->lchild = q->rchild = NULL;
        // t = q;
        return q;
    }
    while (t) {
        p = t;
        if (t->data == x)
            return root;
        else if (x < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    } // reach till required node to insert

    q = (Node *)malloc(sizeof(Node));
    q->data = x;
    q->lchild = q->rchild = NULL;

    if (x < p->data)
        p->lchild = q;
    else
        p->rchild = q;
    return root;
}

// Recursive traversals...
void preorder (Node *p) {
    if (p) {
        printf("%d ", p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder (Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

void postorder (Node *p) {
    if (p) {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ", p->data);
    }
}

// Iterative Traversals

void iterative_preorder (Node *p) { // uses stack
    // D->L->R
    if (!p) return;

    top = NULL; // stack is clean
    while (p != NULL || !isEmptyStack()) {
        if (p != NULL) {
            printf("%d ", p->data);
            push(p);
            p = p->lchild;
        } else {
            p = pop(); // OR temp
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterative_inorder (Node *p) { // uses stack
    // L->D->R
    if (!p) return;

    top = NULL; // stack is clean
    while (p != NULL || !isEmptyStack()) {
        if (p != NULL) {
            push(p);
            p = p->lchild;
        } else {
            p = pop();
            printf("%d ", p->data);
            p = p->rchild;
        }
    }
    printf("\n");
}

void iterative_postorder (Node *p) { // uses stack
    // L->R->D
    if (!p) return;

    top1 = NULL; // stack is clean
    top2 = NULL;

    // 1. Push Root to Stack 1
    push1(p);
    
    while (!isEmptyStack1()) {
        Node *temp = pop1();
        
        // 2. Push to Stack 2 (The result stack)
        push2(temp); 

        // 3. Push Left and Right children to Stack 1
        if (temp->lchild) push1(temp->lchild);
        if (temp->rchild) push1(temp->rchild);
    }

    // 4. Print Stack 2
    while (!isEmptyStack2()) {
        Node *temp = pop2();
        printf("%d ", temp->data);
    }
    printf("\n");
}

int main() {
    root = insert(24, root);
    insert(55, root);
    insert(6, root);
    insert(18, root);
    insert(1, root);
    insert(8, root);
    insert(318, root);

    printf("Pre-order: ");
    preorder(root);
    printf("\n");

    printf("Iterative Pre-order: ");
    iterative_preorder(root);

    printf("In-order: ");
    inorder(root);
    printf("\n");

    printf("Iterative Inorder: ");
    iterative_inorder(root);

    printf("Post-order: ");
    postorder(root);
    printf("\n");

    printf("Iterative Post-order: ");
    iterative_postorder(root);

    return 0;
}