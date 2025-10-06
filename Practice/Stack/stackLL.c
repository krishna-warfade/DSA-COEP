#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// USING LL

typedef struct Node { // stack
    char data;
    struct Node* next;
}Node;

Node *top = NULL;

void push (int x) { // insert
    Node *newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) {
        return;
    }
    else { 
        newnode->data = x;
        newnode->next = top;
        top = newnode;
    }
}

int pop () { // delete
    int x = -1;

    if (top == NULL)
        return -1;
    else {
        x = top->data;
        top = top->next;
    }
    return x;
}

void traverse (Node *p) {
    if (!p)
        return;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void isBalance (char *exp) {
    int ans = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL)
                ans = 0;
            pop();
        }
    }
    if (top == NULL)
        ans = 1;
    else
        ans = 0;
    if (ans)
        printf("Expression is Matching\n");
    else 
        printf("No match\n");
}

int main() {
    char *exp = "(((a+b)*(c-d)))";
    isBalance(exp);
    push(2);
    push(4);

    printf("TOP to BOTTOM : ");
    traverse(top);

    printf("TOPMOST ELEMENT : %d\n", pop());

    printf("TOP to BOTTOM : ");
    traverse(top);

    return 0;
}