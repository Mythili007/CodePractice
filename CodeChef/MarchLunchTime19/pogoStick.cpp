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
        // sum += n;
        // if (n <= 1000 && sum < 10000)
        // {

        lli a[n];
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        lli maxPoints = INT_MIN;

        for (lli i =1; i <= k; i++)
        {
            lli points = 0;
            // long int j = i;
            for (lli j = n-i; j >= 0; j = j - k)
            {
                points = points + a[j];
                cout<<"At j: "<<j<<" points: "<<points<<endl;
                // cout << "points: at position " << j << " is : " << points << endl;

                if (points > maxPoints)
                {
                    maxPoints = points;
                }
                // j = j + k;
            }
        }
        cout << maxPoints << endl;
        // }
    }
    return 0;
}