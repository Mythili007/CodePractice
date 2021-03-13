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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int max = INT_MIN, ans = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            ans = 0;
            for (int j = 0; j < n; j++)
            {
                if (j < i)
                {
                    // cout << "for j: " << j << " and i: " << i << " a[j]: " << a[j] << " and a[i]: " << a[i] << endl;
                    if (a[j] % a[i] == 0)
                        ans += 1;
                } else {
                    break;
                }
            }
            if (ans > max)
                max = ans;
        }
        cout << max << endl;
    }
    return 0;
}