#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a = 5;
    int *b;
    b = &a;
    int **c;
    c = &b;
    cout << "a = " << a << endl;
    cout << "&a = " << &a << endl;
    cout << "b = " << b << endl;
    cout << "&b = " << &b << endl;
    cout << "*b = " << *b << endl;
    cout << "c = " << c << endl;
    cout << "*c = " << *c << endl;
    cout << "**c = " << **c << endl;
    return 0;
}