#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    array arr;
    int pos, key;
    init(&arr, 10);
    append(&arr, 5);
    append(&arr, 10);
    append(&arr, 15);
    append(&arr, 20);
    append(&arr, 25);
    append(&arr, 30);
    append(&arr, 35);
    append(&arr, 40);
    append(&arr, 45);
    // append(&arr, 50);
    display(arr);
    printf("%d ", arr.len);
    insertAtIndex(&arr, 3, -55);
    insertAtIndex(&arr, 2, 6);
    display(arr);

    removeAtIndex(&arr, 5);
    display(arr);

    printf("Max element is %d\n", maxelement(arr));
    printf("Min element is %d\n", minelement(arr));

    reverse(&arr);
    display(arr);

    array crr = merge(&arr, &arr);
    display(crr);
    
    mov_neg(&crr);
    display(crr);

    printf("Enter key to search (Linear Search): ");
	scanf("%d", &key);
    pos = linearSearch(&crr, key);
    if (pos != -1) printf("Key found at index %d\n", pos);
    else printf("Key not found\n");

    bubble_sort(&crr);
    display(crr);

    printf("Enter key to search (Binary Search): ");
    scanf("%d", &key);
    pos = binarySearch(crr, key);
    if (pos != -1) printf("Key found at index %d\n", pos);
    else printf("Key not found\n");

    printf("Original array: ");
    display(arr);
    quickSort(&arr, 0, arr.len - 1);
    printf("Sorted array: ");
    display(arr);
    return 0;
}