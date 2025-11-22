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

// Queue operations start

typedef struct QNode {
    struct Node *treeNode;
    struct QNode *next;
} QNode;

QNode *front, *rear;

void enqueue(Node *t) {
    QNode *q = (QNode*)malloc(sizeof(QNode));
    if(q==NULL) {
        printf("Queue is Full");
    } else {
        q->treeNode=t;
        q->next=NULL;
        if(front==NULL){
            front = rear = q;
        }
        else {
            rear->next=q;
            rear = q;
        }
    }
}

Node *dequeue() {
    Node *t;

    if(front == NULL){
        printf("Queue is empty");
    }else{
        QNode *p = front;
        front = front->next;
        t = p->treeNode;
        free(p);
    }
    return t;
}

int isEmptyQ () {
    return front == NULL;
}

// Queue operations end

int height (Node* root) {
    if (!root)
        return 0;
    int a = 0;
    int b = 0;

    a = height(root->lchild);
    b = height(root->rchild);

    return (a > b) ? (1 + a) : (1 + b);
}

Node *InPre (Node *p) { // inorder predecessor
    // Right most child of left subtree
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *InSucc (Node *p) { // inorder successor
    // Left most child of right subtree
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

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
    while (t) { // reach till required node to insert
        if (t->data == x)
            return root;
        p = t; // even if t becomes null, p is not since it's prev value gets stored in p
        if (x < t->data)
            t = t->lchild;
        else
            t = t->rchild;
    }

    q = (Node *)malloc(sizeof(Node));
    q->data = x;
    q->lchild = q->rchild = NULL;

    if (x < p->data)
        p->lchild = q;
    else
        p->rchild = q;
    return root;
}

Node *Rinsert (int x, Node *p) {
    if (p == NULL) {
        p = (Node*)malloc(sizeof(Node));
        p->data = x;
        p->lchild = p->rchild = NULL;
        return p;
    }
    if (x < p->data) {
        p->lchild = Rinsert(x, p->lchild);
    } else if (x > p->data) {
        p->rchild = Rinsert(x, p->rchild);
    }
    return p;
}

Node *delete (int x, Node *p) {
    if (!p) return NULL;

    Node *q;

    if (x < p->data)
        p->lchild = delete(x, p->lchild);
    else if (x > p->data)
        p->rchild = delete(x, p->rchild);
    else { // reached the node
        if (!p->lchild && !p->rchild) { // leaf node
            if (p == root)
                root = NULL;
            free(p);
            return NULL;
        }
        if (height(p->lchild) > height(p->rchild)) {
            q = InPre(p->lchild); // right most child of left subtree
            p->data = q->data;
            p->lchild = delete(q->data, p->lchild); // we have to physically delete only the predecessor node.

        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = delete(q->data, p->rchild);
        }
    }
    return p;
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

void iterative_postorder (Node *p) { // uses 2 stacks
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

void level_order (Node *p) { // uses queue
    if (!p) return;

    front = NULL;
    rear = NULL;

    enqueue(p);

    while (!isEmptyQ()) {
        Node *temp = dequeue();

        printf("%d ", temp->data);

        if (temp->lchild) enqueue(temp->lchild);
        if (temp->rchild) enqueue(temp->rchild);
    }
    printf("\n");
}

Node *largest (Node *p) {
    if (!p || !p->rchild) {
        printf("Largest data in the node is: %d\n", p->data);
        return p;
    }
    
    return largest(p->rchild);
}

int TotalNodes (Node *p) {
    if (!p)
        return 0;
    else
        return (TotalNodes(p->lchild) + TotalNodes(p->rchild) + 1);
}

int main() {
    root = insert(24, root);
    insert(55, root);
    insert(6, root);
    insert(18, root);
    insert(1, root);
    insert(8, root);
    Rinsert(318, root);
    
    root = delete(318, root);
    printf("Deleted node with data 318\n");

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

    printf("Level order traversal: ");
    level_order(root);

    largest(root);
    printf("Total nodes in the BST: %d\n", TotalNodes(root));
    return 0;
}