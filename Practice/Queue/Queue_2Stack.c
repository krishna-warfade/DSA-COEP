#include <stdio.h>
#include <stdlib.h>
#include "math.h"

struct stack
{
    int size;
    int top;
    int *S;
} st1, st2;

void create(struct stack *st)
{
    printf("Enter size of queue:");
    scanf("%d", &st->size);
    st->top = -1;
    st->S = (int *)malloc(st->size * sizeof(int));
}

void push(struct stack *st, int x)
{
    if (st->top == st->size - 1)
    {
        printf("Queue is Full\n");
    }
    else
    {
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        x = st->S[st->top--];
    }
    return x;
}

int isEmpty(struct stack st)
{
    return st.top == -1;
}

void enqueue(int x)
{
    push(&st1, x);
}

int dequeue()
{
    int x = -1;
    if (isEmpty(st2))
    {
        if (isEmpty(st1))
        {
            printf("Queue empty");
            return x;
        }
        else
        {
            while (!isEmpty(st1))
            {
                push(&st2, pop(&st1));
            }
        }
    }
    return pop(&st2);
}

int main()
{
    create(&st1);
    create(&st2);
    enqueue(2);
    enqueue(25);
    enqueue(22);
    enqueue(29);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());

    return 0;
}