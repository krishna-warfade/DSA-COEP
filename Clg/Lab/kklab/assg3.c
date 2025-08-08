#include <stdio.h>
#include <time.h>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print_array(int arr[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
}

void bub_sort(int arr[], int len) {
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++) {
            if (arr[i] > arr[j]) {
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void sel_sort(int arr[], int len) {
    int min_idx;

    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++)
        {
            min_idx = i;
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }     
            swap(&arr[i], &arr[min_idx]);
        }
    }
}

int main() {
    FILE *fpr;
    fpr = fopen("read_arr.txt", "r");

    read_into_array(fpr);

    clock_t start, t1, t2, tbub, tsel;

    for (int i = 0; i < len; i++)
        arr2[i] = arr1[i];

    start = clock();

    bub_sort(arr1, len);
    t1 = clock();
    tbub = t1 - start;
    
    sel_sort(arr2, len);
    t2 = clock();
    tsel = t2 - t1;

    FILE *fp;
    fp = fopen("wsort.txt", "w");

    fprintf(fp, "1 %f\n2 %f", (double)tbub/(CLOCKS_PER_SEC), (double)tsel/(CLOCKS_PER_SEC));
    fclose(fp);
    return 0;
}