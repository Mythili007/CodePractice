#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n, k;
        cin >> n >> k;
        lli a[n];
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lli x[n * k];
        lli m = 0, counter = 0, sum = 0;
        for (lli i = 0; i < k; i++)
        {
            for (lli j = 0; j < n; j++)
            {
                x[m] = a[j];
                m++;
            }
        }
        for (lli i = 0; i < n; i++)
        {
            counter = 0;
            // cout << "x[i]: " << x[i] << " ";
            for (lli j = 0; j < n; j++)
            {
                if (x[i] > x[j])
                {
                    counter++;
                    sum += k * counter;
                }
            }
            cout << "counter: " << counter << endl;
        }
        cout << sum << endl;
    }
    return 0;
}