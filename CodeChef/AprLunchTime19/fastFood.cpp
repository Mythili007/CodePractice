#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n;
        cin >> n;
        lli a[n], b[n], sum1 = 0, sum2 = 0;
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
            sum1 += a[i];
        }

        for (lli i = 0; i < n; i++)
        {
            cin >> b[i];
            sum2 += b[i];
        }

        if (sum1 > sum2)
        {
            cout << sum1 << endl;
        }
        else if (sum1 < sum2)
        {
            cout << sum2 << endl;
        }
        else
        {
            sort(a, a + n);
            sort(b, b + n);
            cout << (a[n - 1] + b[n - 1]) << endl;
        }
    }
    return 0;
}