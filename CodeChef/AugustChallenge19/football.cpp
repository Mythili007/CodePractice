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
        int a[n], b[n], max = INT_MIN, res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }

        for (int i = 0; i < n; i++)
        {
            res = a[i] * 20 - b[i] * 10;
            if (res < 0)
                res = 0;
            if (res > max)
                max = res;
        }
        cout << max << endl;
    }
    return 0;
}