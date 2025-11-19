#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int size;
    int top;
    int *s;
} Stack;

void create (Stack *st) {
    printf("Enter size of stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int)); 
}

void push (Stack *st, int x) {
    if (st->top == st->size - 1) {
        printf("Stack is full\n");
    } else {
        st->top++;
        st->s[st->top] = x;
    }
}

int pop (Stack *st) {
    int x = -1;

    if (st->top == -1) {
        printf("Stack is empty\n");
    } else {
        x = st->s[st->top];
        st->top--;
    }

    return x;
}

int peek (Stack st, int pos) { // returns the element at a given position from the TOP of the stack.
    int x = -1;
    int index = st.top - pos + 1;

    if (index < 0)
        printf("Invalid Index \n");
    else
        x = st.s[index];
    return x;
}

int isEmpty (Stack st) {
    if (st.top == -1)
        return 1;
    return 0;
}

int isFull (Stack st) {
    return st.top == (st.size - 1);
}

int stackTop (Stack st) {
    return (!isEmpty(st)) ? st.s[st.top] : -1;
}

void display (Stack st) {
    for (int i = st.top; i >= 0; i--)
        printf("%d ", st.s[i]);
    printf("\n");
}

int main() {
    Stack st;

    create(&st);

    push(&st, 6);
    push(&st, 15);
    push(&st, 24);
    push(&st, 33);
    push(&st, 42);
    push(&st, 60);

    display(st);

    printf("Popped element: %d", pop(&st));
    printf("\n");
    display(st);

    printf("Element at index 4 is: %d", peek(st, 4));
}