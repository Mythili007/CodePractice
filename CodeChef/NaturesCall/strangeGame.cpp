#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        sort(a, a + n);
        sort(b, b + n);

        if (a[n - 1] + a[n - 2] > b[n - 1] + b[n - 2])
        {
            cout << "AAYUSHI" << endl;
        }
        else
        {
            cout << "DAKSH" << endl;
        }
    }
    return 0;
}