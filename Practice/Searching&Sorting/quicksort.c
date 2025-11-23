/*
1. Pick up any element as pivot (first/last preferably) and place it on it's correct place in array.
2. Smaller on the left and larger on the right (like move_neg function in ArrayADT).
3. Repeat steps 1 and 2 on the splitted arrays(left and right arrays).
If single array in any of the splittings, it is at it's correct place.
*/

#include<stdio.h>

void swap (int *a, int *b) {
    int temp = *a;

    *a = *b;
    *b = temp;
}

int partition (int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low, j = high;

    while (i < j) {
        while(arr[i] <= pivot && i < high) // finds first element greater than pivot
            i++;
        while (arr[j] > pivot && j > low) // finds first element less than pivot
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]); // place the pivot

    return j;
}

void qsort(int arr[], int low, int high) {
    int partition_idx;

    if (low < high) {
        partition_idx = partition(arr, low, high); // find pivot->place at correct place->return where it is placed
        qsort(arr, low, partition_idx - 1); // sort left
        qsort(arr, partition_idx + 1, high); // sort right
    }
}

int main() {
    int arr[] = {6, 1, 8, 4, 5, 2, 3, 7};

    // print unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        printf("%d ", arr[i]);
    printf("\n");

    qsort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    // print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < (sizeof(arr) / sizeof(arr[0])); i++)
        printf("%d ", arr[i]);
    printf("\n");
}