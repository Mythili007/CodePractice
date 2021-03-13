#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin>>n;
    for (int i = 31; i >= 0; i--)
    {
        k = n >> i;
        if (k & 1)
            cout << 1;
        else
            cout << 0;
    }
    cout << endl;
    return 0;
}