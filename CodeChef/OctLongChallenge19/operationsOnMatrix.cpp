#include <bits/stdc++.h>
using namespace std;
#define ROW 1000
#define COL 1000

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int rows, cols, q, x, y;
        // int a[ROW][COL] = {0};
        long long int a[ROW][COL] = {0};
        cin >> rows >> cols >> q;
        for (int i = 1; i <= q; i++)
        {
            cin >> x >> y;
            // for (int j = 1; j <= rows; j++)
            // {
            //     if (j == x)
            //     {
            for (int k = 1; k <= cols; k++)
            {
                a[x][k] += 1;
            }
            //     }
            // }

            // for (int j = 1; j <= cols; j++)
            // {
            //     if (j == y)
            //     {
            for (int k = 1; k <= rows; k++)
            {
                a[k][y] += 1;
            }
            //     }
            // }
        }
        int count = 0;
        for (int j = 1; j <= rows; j++)
        {
            for (int k = 1; k <= cols; k++)
            {
                if (a[j][k] % 2 != 0)
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}