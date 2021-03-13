#include <bits/stdc++.h>
using namespace std;

int whoWillWin(int n, int m)
{
    int count = 0;
    while (n > 0 || m > 0)
    {
        if (n == 0 || m == 0)
            break;
        if (n >= m)
        {
            int x = 0;
            if (m * 2 < n)
            {
                x = m * 2;
                cout << "x: " << x << endl;
            }
            else
            {
                x = m;
            }
            n = n - x;
            cout << "n: " << n << endl;
            count++;
            // whoWillWin(n, m);
            cout << "count in n:" << count << endl;
        }
        else
        {
            int x = 0;
            if (n * 2 < m)
            {
                x = n * 2;
                cout << "x in else :" << x << endl;
            }
            else
            {
                x = n;
            }
            m = m - x;
            cout << "m: " << m << endl;
            count++;
            // whoWillWin(n, m);
            cout << "count in else: " << count << endl;
        }
    }

    /* int x = 0;
        if (m < n / 2)
        {
            x = n / 2;
            cout << "x: " << x << endl;
        }
        else
        {
            x = m;
            cout << "x in else: " << x << endl;
        }
        n = n - x;
        cout << "n: " << n << endl;
        count++;
        if (n == 0)
            break; */
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, m;
        cin >> n >> m;
        int count = whoWillWin(n, m);
        cout << "count: " << count << endl;
        if (count % 2 == 0)
        {
            cout << "Ari" << endl;
        }
        else
        {
            cout << "Rich" << endl;
        }
    }
    return 0;
}