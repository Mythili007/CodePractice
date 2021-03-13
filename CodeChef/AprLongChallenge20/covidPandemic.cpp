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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int distance = 0, count = 0;
        string res;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] == 1)
                    {
                        distance = j - i;
                        if (distance < 6)
                        {
                            res = "NO";
                            break;
                        }
                    }
                }
            }
            if (distance < 6)
            {
                res = "NO";
                break;
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (a[i] == 1)
                count += 1;
        }
        if (distance >= 6 || count == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}