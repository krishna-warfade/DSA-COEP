/*
MERGE SORT IDEA:
1. Divide the array into 2 halves until you get single elements.
2. Merge the two sorted halves into one sorted array.
3. Repeat merging while returning back from recursion.

If the subarray has 1 element => already sorted.
*/

#include <stdio.h>

void merge (int arr[], int low, int mid, int high) {
    int i = low;      // pointer for left half
    int j = mid + 1;  // pointer for right half
    int k = 0;

    int temp[high - low + 1]; // temporary array

    // Merge both halves into temp[]
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copy remaining elements of left half (if any)
    while (i <= mid)
        temp[k++] = arr[i++];

    // Copy remaining elements of right half (if any)
    while (j <= high)
        temp[k++] = arr[j++];

    // Copy temp back into original array
    for (int x = 0; x < k; x++)
        arr[low + x] = temp[x];
}

void mergeSort (int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Divide
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Conquer (merge sorted halves)
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {6, 1, 8, 4, 5, 2, 3, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // print unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    mergeSort(arr, 0, n - 1);

    // print sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
