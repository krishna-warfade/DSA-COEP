// #include<stdio.h>
// #include<iostream>
// using namespace std;

// struct Rectangle {
//     int length;
//     int breadth;
// };

// int area(struct Rectangle r) {
//     return r.length * r.breadth;
// }
// int perimeter(Rectangle r) {
//     return 2 * (r.length + r.breadth);
// }
// void initialize (Rectangle *r, int l, int b) {
//     r->length = l;
//     r->breadth = b;
// }
// int main() {
//     Rectangle r = {0, 0};
//     cout << "Enter length and breadth of rectangle: ";
//     int l, b;
//     cin >> l >> b;
//     initialize(&r, l, b);
//     int a = area(r);
//     int peri = perimeter(r);

//     printf("Area = %d\nPerimeter = %d\n", a, peri);
//     return 0;
// }

// Object Oriented Program in C++ :

#include <stdio.h>
#include <iostream>
using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    int area()
    {
        return length * breadth;
    }
    int perimeter(Rectangle r)
    {
        return 2 * (length + breadth);
    }
    Rectangle(int l, int b)
    {
        length = l;
        breadth = b;
    }
};
int main()
{
    Rectangle r = {0, 0};
    cout << "Enter length and breadth of rectangle: ";
    int l, b;

    cin >> l >> b;
    r = {l, b};
    int a = r.area();
    int peri = r.perimeter(r);

    printf("Area = %d\nPerimeter = %d\n", a, peri);
    return 0;
}