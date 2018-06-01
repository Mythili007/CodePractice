#include <bits/stdc++.h>
using namespace std;
void changeArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(arr + i);
    }
}
int main()
{
    int a[3];
    // a[0] = 10;
    // a[1] = 20;
    // a[2] = 30;

    int *b;
    b = &a[0];
    cout << "&a[0] : " << &a[0] << endl;
    cout << "&a[1] : " << &a[1] << endl;
    cout << "&a[2] : " << &a[2] << endl;
    cout << "*b : " << *b << endl;
    cout << "b : " << b << endl;
    cout << "b+1 : " << b + 1 << endl;
    cout << "*(b+1) : " << *(b + 1) << endl;
    cout << "*b+1 : " << *b + 1 << endl;
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << a[i] << " ";
    // }
    for(int i = 0;i<3;i++){
        cin>>*(a+i);
    }
    cout << endl;
    // changeArray(a, 3);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}