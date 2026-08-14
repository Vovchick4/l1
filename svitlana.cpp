#include <iostream>

using namespace std;

void printValue(int* x, int* y)

int main()
{
    int a = 5;
    int b = 10;
    cout << "to swap a=" << a << ", b=" << b << endl;
    swapNumbers(&a, &b);
    cout << "After swap: a = " << a << ", b= " << b << endl;
    return 0;
} //комент