#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *lchild;
    struct Node *rchild;
} Node;

Node* root;
// Traversal

Node* create (int val) {
    Node* newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) {
        printf("Malloc failed !!");
        exit(1);
    }
    newnode->lchild = NULL;
    newnode->data = val;
    newnode->rchild = NULL;

    return newnode;
}

Node* insert (Node* root, int val) {
    if (root == NULL)
        root = create(val);
    if (val < root->data)
        root->lchild = insert(root->lchild, val);
    else if (val > root->data)
        root->rchild = insert(root->rchild, val);
    return root;
}

void preorder (Node* root) {
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->lchild);
    preorder(root->rchild);
}

void inorder (Node* root) {
    if (root == NULL)
        return;
    inorder(root->lchild);
    printf("%d ", root->data);
    inorder(root->rchild);
}

void postorder (Node* root) {
    if (root == NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    printf("%d ", root->data);
}

int main() {
    Node *root = NULL;

    root = insert(root, 20);
    root = insert(root, 300);
    root = insert(root, 24);
    root = insert(root, 15);
    root = insert(root, 6);
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    return 0;
}