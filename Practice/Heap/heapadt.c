#include <stdio.h>
#include <stdlib.h>

void swap(int *x, int *y) {
    int temp;

    temp = *x;
    *x = *y;
    *y = temp;
    return;
}

void insert(int A[], int n) { // n = index of the to be inserted element
    int i = n, temp;

    temp = A[i];
    while (i > 1 && temp > A[i / 2]) {
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int delete(int A[], int n) {
    int i, j, x, val;

    val = A[1]; // value to be deleted (returned)
    x = A[n];
    A[1] = A[n];
    A[n]= val;
    i = 1, j = i * 2;

    while (j < n - 1) {
        if (A[j + 1] > A[j])
            j++;
        if (A[i] < A[j]) {
            swap(&A[i], &A[j]);
            i = j;
            j *= 2;
        } else
            break;
    }
    return val;
}



int main() {
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};

    printf("Unsorted Array: \n");
    for (int i = 1; i < (sizeof(H) / sizeof(H[0])); i++)
        printf("%d ", H[i]);
    printf("\n");
    //40, 25, 35, 10, 5, 20, 30
    for (int i = 2; i <= (sizeof(H) / sizeof(H[0])); i++) // start inserting element at index 2
        insert(H, i);

    // insert(H, 2); // insert element at index 2
    // insert(H, 3);
    // insert(H, 4);
    // insert(H, 5);

    // printf("Deleted value is %d\n", delete(H, 7));
    // printf("Deleted value is %d\n", delete(H, 6));

    for (int i = (sizeof(H) / sizeof(H[0])); i > 1; i--) {
        delete(H, i);
    }
    // elements are sorted - #HeapSort
    printf("Sorted Array: \n");
    for (int i = 1; i < (sizeof(H) / sizeof(H[0])); i++)
        printf("%d ", H[i]);

    return 0;
}