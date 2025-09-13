#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int top;
    int *arr;
} Stack;

Stack* createStack() {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    s->arr = (int*)malloc(sizeof(int) * 100);
    s->top = -1;
    return s;
}

void push (Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop (Stack *s) {
    if (s->top == -1) return -1;
    return s->arr[s->top--];
}

int peek (Stack *s) {
    if (s->top == -1) return -1;

    return s->arr[s->top];
}

bool isempty() {
    return s->top == -1;
}