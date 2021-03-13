#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;

    if (a > b)
        return gcd(a - b, b);
    return gcd(a, b - a);
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;

    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;

    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int p[n], count = 0, k = 0;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= i; j++)
            {
                if (i == j)
                {
                    p[k] = i;
                    k++;
                }
                else if (i % j == 0)
                {
                    break;
                }
            }
        }

        /* for (int i = 0; i < k; i++)
        {
            cout << "p[i]: " << p[i] << " ";
        } */

        int a[k][k];
        int max = INT_MIN;
        for (int l = 0; l < k; l++)
        {
            for (int m = 0; m <= k - 1; m++)
            {
                if (l >= 0 && m <= k - 1)
                {
                    a[l][m] = gcd(p[l], p[m]);
                    if (a[l][m] > max && isPrime(a[l][m]))
                        max = a[l][m];
                }
            }
        }

        int freq = 0;

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                // cout << "a[i][j]: " << a[i][j] << endl;
                if (a[i][j] == max)
                {
                    freq++;
                }
            }
        }
        cout << max << " " << freq << endl;
    }
    return 0;
}