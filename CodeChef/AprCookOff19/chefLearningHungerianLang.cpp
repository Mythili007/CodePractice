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
        int a[n][n];
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> a[i][j];
            }
        }
        int counter = 0, counter1 = 0;
        for (int i = 0; i < n; i++)
        {
            counter = 1;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                {
                    counter--;
                }
            }
            if (counter > 0)
            {
                counter1 = 1;
                break;
            }
        }

        for (int j = 0; j < n; j++)
        {
            counter = 1;
            for (int i = 0; i < n; i++)
            {
                if (a[i][j] == 0)
                {
                    counter--;
                }
            }
            if (counter > 0)
            {
                counter1 = 1;
                break;
            }
        }

        if (counter1 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}