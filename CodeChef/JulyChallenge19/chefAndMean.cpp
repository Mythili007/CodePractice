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
        lli a[n], sum = 0;
        for (lli i = 0; i < n; i++)
        {
            cin >> a[i];
            sum += a[i];
        }
        long double mean;
        mean = sum / n;
        cout << "mean: " << mean << endl;
        lli res;
        for (lli i = 0; i < n; i++)
        {
            cout << "a[i]: at " << i << " is: " << a[i] << endl;
            long double mean_lat;
            cout<<"sum: "<<sum<<endl;
            mean_lat = (sum - a[i]) / (n - 1);
            cout<<"mean_lat: "<<mean_lat<<endl;
            if (mean_lat == mean)
            {
                if (i == 0)
                {
                    res = 1;
                    break;
                }
                else
                {
                    res = i + 1;
                    break;
                }
            }
        }
        if (res >= 1)
        {
            cout << res << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        /* // cout<<"mean: "<<mean<<endl;
        if (n % 2 != 0 || sum%n == 0)
        {
            cout << a[((n / 2) + 1)] << endl;
        }
        else if (a[(n/2)+1] == mean)
        {
            cout << "1" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        } */
    }

    return 0;
}