#include <stdio.h>
#include <stdlib.h>
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void SelectionSort(int A[], int n)
{
    int j,k;
    for (int i = 0; i < n - 1; i++)
    {
        for (j = i,k = i; j < n ; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        swap(&A[k], &A[i]);
    }
}

int main()
{
    int arr[] = {4, 6, 2, 9, 98, 76, 23};
    SelectionSort(arr, 7);
    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}