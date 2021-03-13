#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        int a[n], le = 0, res = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        le = 0;
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            le = le + (a[i] - k);
            if (le < 0)
            {
                res = i;
                break;
            }
        }

        if (le < 0)
            cout << "NO " << res << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}