/*
* Commonly implemented using Chaining in Hashing.
* A hash table stores data as (key → value) pairs.
* Bucket (one slot: index) of the table is represented using linked list.
* Supports operarions like:
    - Insert(key, value)
    - Search(key)
    - Delete(key)
*/

#include<stdio.h>
#include "chains.h"

int hash (int key) { // hash function
    return (key % 10);
}

void Insert(Node *H[], int key) {
    int index = hash(key);

    insertSorted(&H[index], key);
}

int main() {
    struct Node *HT[10];
    struct Node *temp;
    int i;

    for (int i = 0; i < 10; i++)
        HT[i] = NULL;
    Insert(HT, 12);
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 24);
    Insert(HT, 32);

    temp = LinearSearch(HT[hash(42)], 42);

    printf("Value %d Found\n", temp->data);
    
    for (int i = 0; i < 10; i++) { // display full hash table
        printf("[%d]-> ", i);
        Display(HT[i]);
        printf("\n");
    }
}