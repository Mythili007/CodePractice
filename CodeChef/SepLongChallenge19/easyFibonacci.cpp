#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], b[n], res = 0, m;
        a[1] = 0, a[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            a[i] = (a[i - 1] + a[i - 2]) % 10;
            // cout << "a[i]: " << a[i] << " ";
        }
        if (n % 2 == 0)
            cout << a[n] << endl;
        else
            cout << a[n - 1] << endl;
    }
    return 0;
}