/* Steps: 
 *
 * CREATE A SPARSE MATRIX
 * INITIALIZE 
 * FILL THE SPARSE MATRIX
 * PRINT IT
 * CREATE ANOTHER SPARSE MATRIX
 * PRINT IT
 * ADD 2 SPARSE MATRICES
 * PRINT RESULTANT MATRIX
 * TRANSPOSE THE MATRIX
 * PRINT THE RESULTANT MATRIX
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
    int size;
    term *arr; // array of elements to be created dynamically
} sparse;

void initialize(sparse *s, int rows, int cols, int size) {
    s->m = rows;
    s->n = cols;
    s->num = 0;
    s->size = size;
    s->arr = (term*) malloc(sizeof(term) * size);
}

void insert(sparse *s, int row, int col, int value) {
    if (value == 0) return;

    if(s->num < s->size) {
        s->arr[s->num].row = row;
        s->arr[s->num].col = col;
        s->arr[s->num].value = value;
        s->num++;
    } else 
        printf("Exceeded non-zero element limit\n");
}

void create(sparse *s) {
    int rows, cols, nonzeros;

    printf("Enter dimensions ");
    scanf("%d%d", &rows, &cols);
    printf("Enter no of non-zero elements ");
    scanf("%d", &nonzeros);

    initialize(s, rows, cols, nonzeros);

    printf("Enter all elements(non-zero) ");
    for(int i = 0; i < nonzeros; i++) {
        int row, col, value;

        scanf("%d%d%d", &row, &col, &value);
        insert(s, row, col, value);
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
