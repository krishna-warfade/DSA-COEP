#include <bits/stdc++.h>

class Node {
    public:
        int data;
        Node *next;
};

class LinkedList {
    private:
        Node* first;
    public:
        LinkedList() {first = NULL;}
        LinkedList(int A[], int n); // constructor
        ~LinkedList(); // destructor

        void display();
        void insert(int index, int x);
        int delete(int index);
        int length();
}