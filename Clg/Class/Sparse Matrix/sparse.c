/* CREATE A SPARSE MATRIX
 * FILL THE SPARSE MATRIX
 * PRINT IT
 * (remaining)INITIALIZE 
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct term {
    int row;
    int col;
    int value;
} term;

typedef struct sparse {
    int m;
    int n;
    int num;
    term *arr; // array of elements to be created dynamically
} sparse;

void create(sparse *s) {
    printf("Enter dimensions ");
    scanf("%d%d", &s->m, &s->n);
    printf("Enter no of non-zero elements ");
    scanf("%d", &s->num);
    s->arr = (term*)malloc(sizeof(term) * s->num);
    printf("Enter all elements(non-zero) ");
    for(int i = 0; i < s->num; i++) {
        scanf("%d%d%d", &s->arr[i].row, &s->arr[i].col, &s->arr[i].value);
    }
    for(int i = 0; i < s->num; i++) {
        printf("%d %d %d\n", s->arr[i].row, s->arr[i].col, s->arr[i].value);
    }
}

void printfullmatrix(sparse s) {
    printf("Full Sparse Matrix:(%dx%d)\n", s.m, s.n);

    for (int i = 0; i < s.m; i++) { // to loop thru every row
        for (int j = 0; j < s.n; j++) { // to loop thru every col of current row
            int found = 0; // (i, j) == non-zero element, search them in next loop
            for (int k = 0; k < s.num; k++) {
                if (s.arr[k].row == i && s.arr[k].col == j) {
                printf("%d ", s.arr[k].value); //print the non-zero value
                found = 1;
                break; // brk inner loop since value is printed
                }
            }
            if (!found) 
                printf("0 "); // if no match found
        }
        printf("\n"); // move to next row
    }
}

int main() {
    sparse s;
    create(&s);

    printfullmatrix(s);

    free(s.arr);
    return 0;
}
