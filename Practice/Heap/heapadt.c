#include <stdio.h>
#include <stdlib.h>

/* HEAP SORT
1. Create a heap of n elements. Time = O(n*log(n))
2. Delete n elements one by one, storing each deleted element at the end of the heap array. Time = O(n*log(n))
    Total time = O(2*n*log(n)) = O(n*log(n))
*/

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
    while (i > 1 && temp > A[i / 2]) { // A[i/2] is it's parent node
        A[i] = A[i / 2];
        i = i / 2;
    }
    A[i] = temp;
}

int delete(int A[], int n) {
    int i, j, x, val;

    val = A[1]; // value to be deleted (returned), largest value
    x = A[n];
    A[1] = A[n];

    A[n]= val; // in place replacement of the largest element to last position, so as to sort the array.
    i = 1, j = i * 2;

    while (j < n - 1) {
        if (A[j + 1] > A[j]) // rchild > lchild
            j++;
        if (A[i] < A[j]) { // parent < child, interchange
            swap(&A[i], &A[j]);
            i = j;
            j *= 2; // going towards it's children
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
    // 10 20 30 25 5 40 35 
    printf("\n");

    // start inserting element at index 2, considering first is already sorted
    for (int i = 2; i <= (sizeof(H) / sizeof(H[0])); i++)
        insert(H, i);

    // printf("Deleted value is %d\n", delete(H, 7));
    // printf("Deleted value is %d\n", delete(H, 6));

    // starting from last index so as to decrement array size
    for (int i = (sizeof(H) / sizeof(H[0])); i > 1; i--) {
        delete(H, i);
    }

    // elements are sorted - #HeapSort
    printf("Sorted Array: \n");

    for (int i = 1; i < (sizeof(H) / sizeof(H[0])); i++)
        printf("%d ", H[i]);
    // 5 10 20 25 30 35 40
    return 0;
}