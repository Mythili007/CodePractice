#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, minX, maxX, x = 1, weight[n], bias[n], res, oddCount=0, evenCount=0;
    cin >> t;
    // cin.ignore(1);
    while (t-- > 0)
    {
        cin >> n >> minX >> maxX;
        for (int i = 0; i < n; i++)
        {
            cin >> weight[i] >> bias[i];
        }

        for (int i = minX; i <= maxX; i++)
        {
            for (int k = 0; k < n; k++)
            {
                res = (weight[k] * res) + bias[k];
            }
            cout << "res: " << res << endl;
            if (res % 2 == 0)
            {
                evenCount += 1;
            }
            else
            {
                oddCount += 1;
            }
        }
        cout << evenCount << " " << oddCount << endl;
    }
    return 0;
}