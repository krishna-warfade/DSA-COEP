#include<stdio.h>
#include<iostream>
using namespace std;

struct Rectangle {
    int length;
    int breadth;
};

int area(struct Rectangle r) {
    return r.length * r.breadth;
}
int perimeter(struct Rectangle r) {
    return 2 * (r.length + r.breadth);
}
int main() {
    Rectangle r = {0, 0};
    cout << "Enter length and breadth of rectangle: ";
    cin >> r.length >> r.breadth;
    int a = area(r);
    int peri = perimeter(r);

    printf("Area = %d\nPerimeter = %d\n", a, peri);
    return 0;
}