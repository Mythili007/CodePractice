#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, sum = 0, count = 0;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 1)
                count++;
            // sum+=a[i];
        }
        if (count <= k)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}