#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// USING ARRAY

typedef struct st {
    int size;
    int top;
    int *arr;
}st;

void create(st *stack) {
    printf("Enter Size: ");
    scanf("%d", &stack->size);
    stack->arr = (int *)malloc(stack->size * sizeof(stack));
    stack->top = 0;
}

void push (st *s, int x) {
    if (s->top > s->size - 1) {
        printf("Stack Overflow\n");
        return;
    } else
        s->arr[s->top++] = x;
}

int pop (st *s) {
    int x = -1;

    if (s->top > s->size - 1) {
        printf("Stack Overflow\n");
        return x;
    } else {
        s->top--;
        x = s->arr[s->top];
    }
    return x;
}

void traverse (st s) {
    for (int i = s.top - 1; i >= 0; i--)
        printf("%d ", s.arr[i]);
    printf("\n");
}

int main() {
    st st;

    create (&st);

    push(&st, 2);
    push(&st, 4);
    push(&st, 6);

    printf("TOP to BOTTOM : ");
    traverse(st);
    printf("Popped element : %d\n",pop(&st));
    printf("TOP to BOTTOM : ");
    traverse(st);
}