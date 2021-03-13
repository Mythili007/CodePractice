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
        int a[n], b[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            b[i] = a[i];
        }
        sort(a, a + n);
        int min = a[0], max = a[n - 1], min_ind, max_ind;
        for (int i = 0; i < n; i++)
        {
            if (min == b[i])
            {
                min_ind = i;
            }

            if (max == b[i])
            {
                max_ind = i;
            }
        }

        if (min_ind > max_ind)
        {
            cout << max << " " << min << endl;
        }
        else
        {
            cout << min << " " << max << endl;
        }
    }
    return 0;
}