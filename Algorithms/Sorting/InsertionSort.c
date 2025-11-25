#include <stdio.h>

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j;
        int x = A[i];
        j = i - 1;
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

int main()
{
    int arr[] = {2, 5, 4, 7, 2, 4, 3, 53, 8, 75, 94};
    InsertionSort(arr, 11);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}