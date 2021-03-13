#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, count=0;
        cin >> n >> k;
        int a[n+1];
        a[0]=0;
        for (int i = 1; i < n+1; ++i)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            if ((a[i + 1] - a[i]) % k == 0)
            {
                count += (((a[i + 1] - a[i]) / k) - 1);
            }
            else
            {
                count += ((a[i + 1] - a[i]) / k);
            }
        }
        cout<<count<<endl;
    }
    return 0;
}