#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// USING LL

typedef struct Node { // stack
    char data;
    struct Node* next;
}Node;

Node *top = NULL;

void push (char x) { // insert
    Node *newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) 
        return;
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

char pop () { // delete

    if (top == NULL)
        return -1;

    Node* temp = top;
    char x = temp->data;
    top = top->next;
    free(temp);

    return x;
}

char topele () {
    char x;

    if (top == NULL)
        return -1;
    else
        x = top->data;
    return x;    
}

int prece (char opr) {
    if (opr == '*' || opr == '/')
        return 3;
    else if (opr == '+' || opr == '-')
        return 2;
    else if (opr == '(')
        return 1;
    return 0;
}

void eval (char* s) {
    int i = 0, j = 0;
    char res[100] = "";

    while (s[i] != '\0') {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                res[j++] = s[i];
        else if (s[i] == '(')
            push(s[i]);
        else if (s[i] == ')') {
            while (topele() != '(')
                res[j++] = pop();
            pop();
        } else {            
            while (top != NULL && prece(topele()) >= prece((s[i])))
                res[j++] = pop();
            push(s[i]);
        }
        i++;
    }
    while (top != NULL) {
        res[j++] = pop();
    }
    res[j] = '\0';
    printf("%s\n", res);
}

int main () {
    char s[100] = "((a+b)-c*d-e+j)";

    eval(s);
    return 0;
}