#include<stdio.h>

int linearSearch(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 3, 24, 33, 42, 4, 6, 11, 15, 60, 66};
    int idx = linearSearch(arr, 11, 24);

    printf("Value found at index: %d\n", idx);
    return 0;
}