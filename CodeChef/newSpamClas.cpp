#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t=0, n=0, oddCount=0, evenCount=0,k;
    long long int minX=0, maxX=0, weight[n], bias[n], i=0, res = minX;
    cin >> t;
    // cin.ignore(1);
    while (t-- > 0)
    {
        cin >> n >> minX >> maxX;
        for (i = 0; i < n; i++)
        {
            cin >> weight[i] >> bias[i];
        }

        for (i = minX; i <= maxX; i++)
        {
            for ( k = 0; k < n; k++)
            {
                res = (weight[k] * i) + bias[k];
            }
            // cout << "res: " << res << endl;
            if (res % 2 == 0)
            {
                evenCount += 1;
            }
            if (res % 2 != 0)
            {
                oddCount += 1;
            }
        }
        cout << evenCount << " " << oddCount << endl;
    }
    return 0;
}