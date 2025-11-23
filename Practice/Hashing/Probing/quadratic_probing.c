#include <stdio.h>
#define SIZE 10

void Print(int vec[], int n, const char *s) {
    printf("%s: [", s);
    for (int i = 0; i < n; i++) {
        printf("%d", vec[i]);
        if (i < n - 1)
            printf(", ");
    }
    printf("]\n");
}

int Hash(int key) {
    return key % SIZE;
}

int QuadraticProbe(int H[], int key) {
    int idx = Hash(key);
    int i = 0;

    while (H[(idx + i * i) % SIZE] != 0)
        i++;
    return (idx + i * i) % SIZE;
}

void Insert(int H[], int key) {
    int idx = Hash(key);

    if (H[idx] != 0)
        idx = QuadraticProbe(H, key);
    H[idx] = key;
}

int Search(int H[], int key) {
    int idx = Hash(key);
    int i = 0;

    while (H[(idx + i * i) % SIZE] != key) {
        i++;
        if (H[(idx + i * i) % SIZE] == 0)
            return -1;
    }
    return (idx + i * i) % SIZE;
}

int main() {
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A) / sizeof(A[0]);

    Print(A, n, "A");

    int HT[SIZE] = {0};

    for (int i = 0; i < n; i++)
        Insert(HT, A[i]);

    Print(HT, SIZE, "HT");

    int index = Search(HT, 25);
    printf("key found at: %d\n", index);

    index = Search(HT, 35);
    printf("key found at: %d\n", index);

    return 0;
}
