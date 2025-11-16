/*Remove duplicates from an array of doubles*/

#include <stdio.h>
int main() {
    double arr[] = {1.0, 2.0, 2.0, 3.0, 4.0, 4.0, 5.0, 6, 6.0, 7.0, 8.0, 9.0, 9.0, 10.0, 10.0, 11.0, 12.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0, 20.0, 21.0, 22.0, 23.0, 24};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Array before removing duplicates: \n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    int i = 0;
    for (int j = 1; j < n; j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];            
        }
    }
    printf("\n");
    printf("Array after removing duplicates: \n");
    for (int k = 0; k <= i; k++) { // New Length = i
        printf("%.2f ", arr[k]);
    }
    printf("\n");
    
    return 0;
}
