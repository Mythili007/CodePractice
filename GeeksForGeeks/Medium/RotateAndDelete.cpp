#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t = 0, len = 0, n = 0, a[n], b[n];
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        while (n != 1)
        {
            for (int i = 0; i < n; i++)
            {
                if (i == 0)
                {
                    b[i] = a[n - 1];
                }
                else
                {
                    b[i] = a[i - 1];
                }
            }
            /* after rotation delete the last element*/
            len = n;
            
        }
        // for (int i = 0; i < n; i++)
        // {
        //     cout << b[i] << " ";
        // }
    }
    return 0;
}