#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, a[n];
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            if (a[i] % a[0] == 0)
            {
                cout << a[i] / a[0] << " ";
            }
            else
            {
                cout << a[i] << " ";
            }
        }
    }
    return 0;
}
