#include <stdio.h>
#include <stdlib.h>
#include "header.h"

array arr1, arr2, arr3;

void init(array *arr, int size){
    arr -> size = size;
    arr -> len = 0;
    arr -> A = (int *)malloc(sizeof(int) * size);
}

void append(array *arr, int value){
    if(arr -> len < arr -> size){
        arr -> A[arr -> len++] = value;
    }else{
        return;
    }
}

void insertAtIndex(array *arr, int index, int value){
    if(index < 0 || index > arr -> len){
        printf("Invalid Index\n");
    }else if(arr -> len >= arr -> size){
        printf("Array is Full\n");
    }else{
        for(int i = arr -> len; i > index; i--){
            arr -> A[i] = arr -> A[i - 1]; 
        }
        arr -> A[index] = value;
        arr -> len++;
    }
}

void removeAtIndex(array *arr, int index){
    if(index < 0 || index >= arr -> len){
        printf("Invalid Index\n");
    }else{
        for(int i = index; i < arr -> len - 1; i++){
            arr -> A[i] = arr -> A[i + 1];
        }
        arr -> len--;
    }
}

void display(array arr){
    for(int i = 0; i < arr.len; i++){
        printf("%d ", arr.A[i]);
    }
    printf("\n");
    return;
}

int maxelement(array arr){
    int max = arr.A[0];
    for(int i = 1; i < arr.len; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    }
    return max;
}

int minelement(array arr){
    int min = arr.A[0];
    for(int i = 1; i < arr.len; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    }
    return min;
}

void reverse(array *arr){
    for(int i = 0, j = arr -> len - 1; i < arr -> len / 2; i++, j--){
        int temp = arr -> A[i];
        arr -> A[i] = arr -> A[j];
        arr -> A[j] = temp;
    }
}

array merge(array *arr, array *brr){
    array crr;
    init(&crr, arr -> len + brr -> len);
    for(int i = 0; i < arr -> len; i++){
        crr.A[i] = arr -> A[i];
        crr.len++;
    }
    for(int i = 0; i < brr -> len; i++){
        append(&crr, brr -> A[i]);
    }
    return crr;
}

void mov_neg(array * arr){
    int i = 0, j = arr -> len - 1;
    while(i < j){
        while(arr -> A[i] < 0){
            i++;
        }
        while(arr -> A[j] >= 0){
            j--;
        }     
        if(i < j){
            int temp = arr -> A[i];
            arr -> A[i] = arr -> A[j];
            arr -> A[j] = temp;
        }
    }
}

int linearSearch(array *arr, int key){
    int i;
    for(i = 0; i < arr -> len; i++){
        if(key == arr -> A[i]){
            return i;
        }
    }
    return -1;
}

int binarySearch(array arr, int key) {
    int l, h, mid, result = -1;
    l = 0;
    h = arr.len - 1;

    while (l <= h) {
        mid = (l + h) / 2;
        if (key == arr.A[mid]){
            result = mid;
            // h = mid - 1;
            break;
        }else if (key < arr.A[mid]) {
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return result;
}

int RBinSearch(array arr, int l, int h, int key){
    int mid;
    
    if(l <= h){
        
        mid = (l + h) / 2;
        if(key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return RBinSearch(arr, l, mid - 1, key);
        else 
            return RBinSearch(arr, mid + 1, h, key);
    }
    return -1;
}

void bubble_sort(array *arr){
	int i, j, temp;
	for(int i = 0; i < arr -> len - 1; i++){
		for(int j = 0; j < arr -> len - 1 - i; j++){
			if(arr -> A[j] > arr -> A[j+1]){
				temp = arr -> A[j];
				arr -> A[j] = arr -> A[j + 1];
				arr -> A[j + 1] = temp;
			}
		}
	}
}

void insertion_sort(array *arr) {
    int i, j, key;
    for (i = 1; i < arr -> len; i++) {  
        key = arr -> A[i];  
        j = i - 1;

        while (j >= 0 && arr -> A[j] > key) {
            arr -> A[j + 1] = arr -> A[j];
            j = j - 1;
        }
        arr -> A[j + 1] = key;  
    }
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(array *arr, int low, int high) {
    int pivot = arr->A[low]; // Choose the first element as pivot
    int i = low + 1;         // Start from the second element
    int j = high;            // Start from the last element
    while (i <= j) {
        // Find elements on wrong sides
        while (arr->A[i] <= pivot) i++;
        while (arr->A[j] > pivot) j--;

        if (i < j) {
            // Swap out-of-place elements
            swap(&arr->A[i], &arr->A[j]);
        }
    }
    // Place pivot in its correct position
    swap(&arr->A[low], &arr->A[j]);
    return j; // Return the pivot index
}

void quickSort(array *arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1);        
        quickSort(arr, pi + 1, high);      
    }
}

void selection_sort(array *arr){
	int i, j, min_index, temp;
	for(int i = 0; i < arr -> len - 1; i++){
		min_index = i;
		for(int j = i + 1; j < arr -> len; j++){
			if(arr -> A[j] < arr -> A[min_index]){
				min_index = j;
			}
		}
		if(min_index != i){
			temp = arr -> A[i];
			arr -> A[i] = arr -> A[min_index];
			arr -> A[min_index] = temp; 
		}
	}
}

//
int isSorted(array arr) {
    int i;
    for(i = 0; i < arr.len - 1; i++){
        if(arr.A[i] > arr.A[i + 1])
            return 0;
    }
    return 1;
}

void REarrange(array *arr) { // same as move neg
    int i = 0, j = arr -> len - 1;
    while(i < j){
        while(arr -> A[i] < 0){i++;}
        while(arr -> A[j] >= 0){j--;}     
        if(i < j)
            swap(&arr -> A[i], &arr -> A[j]);
    }
}

array *Merge(array *arr1, array *arr2) {
    int i,j,k;
    i=j=k=0;
    array *arr3=(array *)malloc(sizeof(array));

    while(i < arr1->len && j < arr2 -> len){
        if(arr1 -> A[i] < arr2 -> A[j])
            arr3 -> A[k++] = arr1 -> A[i++];
        else
            arr3 -> A[k++] = arr2 -> A[j++];
    }
    for(;i < arr1 -> len; i++)
        arr3 -> A[k++] = arr1 -> A[i];
    for(;j < arr2 -> len; j++)
        arr3 -> A[k++] = arr2 -> A[j];
    arr3 -> len = arr1 -> len + arr2 -> len;
    arr3 -> size=10;
    return arr3;
}

array *Union(array *arr1,array *arr2) {
    int i,j,k;
    i=j=k=0;

    array *arr3=(array *)malloc(sizeof(array));

    while(i < arr1 -> len && j < arr2 -> len){
        if(arr1 -> A[i] < arr2 -> A[j])
            arr3 -> A[k++] = arr1 -> A[i++];
        else if(arr2 -> A[j] < arr1 -> A[i])
            arr3 -> A[k++] = arr2 -> A[j++];
        else{
            arr3 -> A[k++] = arr1 -> A[i++];
            j++;
        }
    }  
    for(;i < arr1 -> len; i++)
        arr3 -> A[k++]= arr1 -> A[i];
    for(;j < arr2 -> len; j++)
        arr3 -> A[k++]= arr2 -> A[j];

    arr3 -> len = k;
    arr3 -> size = 10;

    return arr3;
}

array *Intersection(array *arr1,array *arr2) {
    int i,j,k;
    i=j=k=0;

    array *arr3 = (array *)malloc(sizeof(array));

    while(i < arr1 -> len && j < arr2 -> len){
        if(arr1 -> A[i] < arr2 -> A[j])
            i++;
        else if(arr2 -> A[j] < arr1 -> A[i])
            j++;
        else if(arr1 -> A[i] == arr2 -> A[j]){
            arr3 -> A[k++] = arr1 -> A[i++];
            j++;
        }
    }

    arr3 -> len = k;
    arr3 -> size = 10;

    return arr3;
}

array *Difference(array *arr1,array *arr2) {
    int i,j,k;
    i=j=k=0;

    array *arr3 = (array *)malloc(sizeof(array));

    while(i < arr1->len && j < arr2 -> len){
        if(arr1 -> A[i] < arr2 -> A[j])
            arr3 -> A[k++] = arr1 -> A[i++];
        else if(arr2 -> A[j] < arr1 -> A[i])
            j++;
        else{
            i++;
            j++;
        }
    }
    
    for(;i < arr1 -> len; i++)
    arr3 -> A[k++] = arr1 -> A[i];

    arr3 -> len = k;
    arr3 -> size = 10;

    return arr3;
}
