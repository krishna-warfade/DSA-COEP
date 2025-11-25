#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node *top = NULL;

void push (int x) { // insert at FIRST position always
    Node *newnode = (Node*)malloc(sizeof(Node));

    if (newnode == NULL) {
        return; // malloc failed
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
        return x;
    else {
        Node *temp = top;
        x = top->data;
        top = top->next;
        free(temp);
    }
    return x;
}

int isEmptyStack () {
    return top == NULL;
}

int peek (int pos) {
    int x = -1;

    if (top == NULL)
        printf("Stack is empty\n");
    else {
        Node *temp = top;
        for (int i = 0; i < pos - 1 && temp; i++) // reach till posn
            temp = temp->next;
        if (temp)
            x = temp->data;
    }
    return x;
}

int topEle () {
    int x = -1;

    if (!isEmptyStack()) {
        x = top->data;
    }
    return x;
}

void display (Node *p) {
    if (!p)
        return;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void isBalance (char *exp) { // exp[]
    int ans = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (top == NULL)
                ans = 0;
            else
                pop();
        }
    }
    if (top == NULL)
        ans = 1;
    // else
    //     ans = 0;
    if (ans) printf("Expression is Matching\n");
    else printf("No match\n");
}

/* Conversions */

int prio(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    return -1;
}

// 1. infix to postfix

char* infTopostf(char *str, char *ans) {
    int i = 0, j = 0;
    char x;

    while(i < strlen(str)) { // str[i] != '\0'

        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
        {
            ans[j++] = str[i];
        } else if (str[i] == '(') {
            push(str[i]);
        } else if (str[i] == ')') {
            while (!isEmptyStack() && topEle() != '(')
                ans[j++] = pop();
            // got the opening bracket '(', pop it
            x = pop();
        } else { // operator
            while(!isEmptyStack() && prio(topEle()) >= prio(str[i])) { // if operator (to be checked, has lesser priority, it can't be popped onto the answer string, stack top has to be popped to answer)
                ans[j++] = pop();
            }
            push(str[i]); // push the current operator
        }
        i++;
    }
    // empty the remng stack
    while (!isEmptyStack())
        ans[j++] = pop();

    ans[j] = '\0';
    return ans;
}

void swap (char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}

char *reverse (char *str) {
    for (int i = 0, j = strlen(str) - 1; i < j; i++, j--)
        swap(&str[i], &str[j]);
    return str;
}

char* infTopref(char *str, char *prefans) {
    char temp[strlen(str) + 1];
    strcpy(temp, str);
    reverse(temp);
    int i = 0, j = 0;

    while(i < strlen(temp)) {
        if ((str[i] >= 'A' && str[i] <= 'Z') ||
            (str[i] >= 'a' && str[i] <= 'z') ||
            (str[i] >= '0' && str[i] <= '9'))
            {
                prefans[j++] = temp[i];
            }
            else if (str[i] == '(') {
                push(str[i]);
            } else if (str[i] == ')') {
                while (!isEmptyStack() && topEle() != '(')
                    prefans[j++] = pop();
                pop();
        } else {
            if (temp[i] == '^') {
                while(!isEmptyStack() && prio(temp[i]) < prio(topEle())) {
                    prefans[j++] = pop();
                }
            } else {
                while (!isEmptyStack() && prio(temp[i]) < prio(topEle())) {
                    prefans[j++] = pop();
                }
            }
            push(temp[i]);
        }
        i++;
    }
    while (!isEmptyStack())
    {
        prefans[j++] = pop();
    }
    prefans = reverse(prefans);

    return prefans;
}

int main() {
    char *exp = "(a+b)*(c-d)";
    char ans[strlen(exp) + 1];
    char prefans[strlen(exp) + 1];

    // isBalance(exp);
    // push(2);
    // push(4);

    // printf("TOP to BOTTOM : ");
    // display(top);

    // printf("Popped element : %d\n", pop());

    // printf("TOP to BOTTOM : ");
    // display(top);

    printf("Original expression: %s\n", exp);
    printf("Infix to postfix: %s\n", infTopostf(exp, ans));
    printf("Infix to prefix: %s\n", infTopref(exp, prefans));

    return 0;
}