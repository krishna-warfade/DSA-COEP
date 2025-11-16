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

Node* search (Node* root, int val) {
    if (!root || root->data == val)
        return root;
    if (val < root->data)
        return search(root->lchild, val);
    else
        return search(root->rchild, val);
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

void leafNodes (Node* root) {
    if (!root)
        return;
    if (root->lchild == NULL && root->rchild == NULL)
        printf("%d ", root->data);
    leafNodes(root->lchild);
    leafNodes(root->rchild);
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

    int choice, val;

    do {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n2. Delete Node\n3. Search Node\n4. Traversals\n5. Depth of Tree\n6. Display Leaf Nodes\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val))
                    printf("Value %d found in BST.\n", val);
                else
                    printf("Value %d not found.\n", val);
                break;

            case 4:
                printf("Inorder: "); inorder(root);
                printf("\nPreorder: "); preorder(root);
                printf("\nPostorder: "); postorder(root);
                printf("\n");
                break;

            case 5:
                printf("Depth of Tree: %d\n", depth(root));
                break;

            case 6:
                printf("Leaf Nodes: ");
                leafNodes(root);
                printf("\n");
                break;

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid Choice! Try again.\n");
        }

    } while (choice != 7);
    return 0;
}