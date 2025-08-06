/*Compare time complexities of 2 sorting algorithms. Create a set of integers varying in thousands in a file & 
 *sort the file using 2 sorting algorithms.
 *Plot graph of time taken by both the programs using : gnuplot*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap (int a[], int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubble_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                swap(a, j, j + 1);
            }
        }
    }
}

void selection_sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        swap(a, i, min_index);
    }
}

int main() {
    clock_t start, bubble_time, selsort_time, t1, t2;
    int arr[] = {1500, 2400, 1333, 5643, 1234, 4321, 9876, 5432, 6789, 2345, 3456, 4567, 7890, 8765, 3210, 
                   1357, 2468, 3579, 4680, 5791, 6802, 7913, 1824, 9135, 1024, 4058, 5736, 2648,
                   3847, 4956, 5067, 6178, 7289, 8390, 9401, 1052, 2163, 3274, 4385, 5496, 
                   6507, 7618, 8729, 9830, 1091, 2102, 3213, 4324, 5435, 6546, 7657, 8768,
                   9879, 1234, 2345, 3456, 4567, 5678, 6789, 7890, 8901, 9012, 1023, 1134,
                   1245, 1356, 1467, 1578, 1689, 1790, 1901, 2012, 2123, 2234, 2345, 2456, 2567,
                    2678, 2789, 2890, 2901, 3012, 3123, 3234, 3345, 3456, 6};

    int n = sizeof(arr) / sizeof(arr[0]);
    int arrtwo[n];

    // Copy of the original array for selection sort
    for (int i = 0; i < n; i++) {
        arrtwo[i] = arr[i];
    }

    start = clock();

    bubble_sort(arr, n);
    t1 = clock();
    bubble_time = t1 - start;

    selection_sort(arrtwo, n);
    t2 = clock();
    selsort_time = t2 - t1;

    FILE *fp = fopen("op.txt", "w");

    if (fp == NULL) {
        printf("Error opening file");
        return 0;
    }
    fprintf(fp, "1 %f\n2 %f", (double) bubble_time / CLOCKS_PER_SEC, (double) selsort_time / CLOCKS_PER_SEC);
    fclose(fp);
    
    printf("Bubble Sort Time: %f seconds\n", (double) bubble_time / CLOCKS_PER_SEC);
    printf("Selection Sort Time: %f seconds\n", (double) selsort_time / CLOCKS_PER_SEC);

    system("gnuplot -e \"set terminal png; set output 'sort_analysis.png'; plot 'op.txt' with lines\"");

    return 0;
}
