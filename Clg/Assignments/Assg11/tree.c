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
        return create(val);
    if (val < root->data)
        root->lchild = insert(root->lchild, val);
    else if (val > root->data)
        root->rchild = insert(root->rchild, val);
    return root;
}

Node* minNodeValue (Node* node) {
    while (node != NULL && node->lchild != NULL)
        node = node->lchild;
    return node;
}

Node* delete (Node* root, int val) {
    if (!root)
        return root;
    if (val < root->data)
        root->lchild = delete(root->lchild, val);
    else if (val > root->data)
        root->rchild = delete(root->rchild, val);
    else {
        if (!root->lchild) {
            Node* temp = root->rchild;
            free(root);
            return temp;
        } else if (!root->rchild) {
            Node* temp = root->lchild;
            free(root);
            return temp;
        }
        Node* temp = minNodeValue(root->rchild);
        root->data = temp->data;
        root->rchild = delete(root->rchild, temp->data);
    }
    return root;
}

Node* search (Node* root, int val) {
    if (root == NULL || root->data == val)
        return root;
    if (val < root->data)
        return search(root->lchild, val);
    return search(root->rchild, val);
}

int depth (Node* root) {
    if (!root)
        return 0;
    int l = depth(root->lchild);
    int r = depth(root->rchild);

    return (l > r ? l : r) + 1; // + 1 for root
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