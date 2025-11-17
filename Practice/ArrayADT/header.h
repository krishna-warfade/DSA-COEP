typedef struct array{
    int *A;
    int size;
    int len;
}array;

void init(array *arr, int size);
void append(array *arr, int value);
void insertAtIndex(array *arr, int index, int value);
void removeAtIndex(array *arr, int index);
void display(array arr);
int maxelement(array arr);
int minelement(array arr);
void reverse(array *arr);
array merge(array *arr, array *brr);
void mov_neg(array * arr);

int linearSearch(array *arr, int key);
int binarySearch(array arr, int key);
int RBinSearch(array arr,int l,int h,int key);
void bubble_sort(array *arr);
void insertion_sort(array *arr);

void swap(int *a, int *b);
int partition(array *arr, int low, int high);
void quickSort(array *arr, int low, int high);
void selection_sort(array *arr);

//
int isSorted(array arr);
void REarrange(array *arr);
array *Merge(array *arr1, array *arr2);
array *Union(array *arr1,array *arr2);
array *Intersection(array *arr1,array *arr2);
array *Difference(array *arr1,array *arr2);