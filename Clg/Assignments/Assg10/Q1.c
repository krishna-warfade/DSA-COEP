#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node { // stack
    char data;
    struct Node* next;
} Node;

Node *top = NULL;

void push (char x) { // insert
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

char pop () { // delete

    if (top == NULL)
        return '\0'; // stack empty

    Node *temp = top;
    char x = top->data;
    top = top->next;
    free(temp);
    return x;
}

bool match (char open, char close) {
    if (open == '(' && close == ')') return true;
    if (open == '{' && close == '}') return true;
    if (open == '[' && close == ']') return true;
    return false;
}

void isBalance (char *exp) {
    int ans = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            push(exp[i]);
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (top == NULL) {
                ans = 0;
            }
            char x = pop();
            if (!match(x, exp[i])) {
                printf("No match\n");
                return;
            }
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
    char *exp = "((a+b}*(c-d)))";
    isBalance(exp);
    push(2);
    push(4);

    return 0;
}