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
        lli a[n];
        lli x = 0;
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        lli min = INT_MAX, sum = 0;
        for (lli i = 0; i < n; i++)
        {
            x = a[i];
            sum = 0;
            for (lli j = 0; j < n; j++)
            {
                if (a[i] != a[j])
                    sum += (x ^ a[j]);
                // cout<<"sum: "<<sum<<endl;
            }
            if (sum < min)
            {
                min = sum;
                // cout<<"min: "<<min<<endl;
            }
        }
        cout << min << endl;
    }
    return 0;
}