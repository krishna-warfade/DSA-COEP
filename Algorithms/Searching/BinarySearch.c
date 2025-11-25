#include<stdio.h>

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 4, 6, 11, 15, 24, 33, 42, 60, 66};
    int idx = binarySearch(arr, 11, 24);

    printf("Value found at index: %d\n", idx);
    return 0;
}