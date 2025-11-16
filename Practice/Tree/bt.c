#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} Node;

Node *root = NULL;

Node *Rsearch(int key, Node *t) {
    if (!t)
        return NULL;
    if (t->data == key)
        return t;
    else if (key > t->data)
        return Rsearch(key, t->rchild);
    else
        return Rsearch(key, t->lchild);
}

int Rcount (Node *root) {
    if (root)
        return 1 + Rcount(root->lchild) + Rcount(root->rchild);
    return 0;
}

int height (Node* root) {
    int a = 0;
    int b = 0;

    if (root == 0)
        return 0;
    a = height(root->lchild);
    b = height(root->rchild);

    return (a > b) ? (1 + a) : (1 + b);
}

Node *insert (int x, Node *t) {
    Node *p, *q;

    Node *root = t;
    p = NULL;
    if (!t) { // inserting / initializing as root
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

Node *inorder_predec (Node *p) { // for largest value in left subtree by going as right as possible
    while (p && p->rchild)
        p = p->rchild;
    return p;
}

Node *inorder_succ (Node *p) { // receives right subtree of a node and goes as left as possible
    while (p && p->lchild)
        p = p->lchild;
    return p;
}

Node *delete (int key, Node *t) {
    if (!t)
        return NULL;
    
    if (key < t->data)
        t->lchild = delete(key, t->lchild);
    else if (key > t->data)
        t->rchild = delete(key, t->rchild);
    else { // key node found
        if (!t->lchild && !t->rchild) {
            free(t);
            return NULL;
        }
        else if (height(t->lchild) > height(t->rchild)) {
            Node *predecessor = inorder_predec(t->lchild);

            t->data = predecessor->data;
            t->lchild = delete(predecessor->data, t->lchild);
        }
        else {
            Node *successor = inorder_succ(t->rchild);

            t->data = successor->data;
            t->rchild = delete(successor->data, t->rchild);
        }
    }
    return t;
}

void inorder (Node *p) {
    if (p) {
        inorder(p->lchild);
        printf("%d ", p->data);
        inorder(p->rchild);
    }
}

int main() {
    root = insert(24, root);
    insert(55, root);
    insert(6, root);
    insert(18, root);

    inorder(root);
    printf("\n");

    Node* found = Rsearch(6, root);
    if (found)
        ("%d\n", found->data);
    
    root = delete(6, root);
    inorder(root);
    printf("\n");
    
    return 0;
}