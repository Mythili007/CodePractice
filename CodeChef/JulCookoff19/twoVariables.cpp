#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long xf;
        cin >> xf;
        long x = 0, y = 0, c = 0;

        for (long i = 0; i < ; i++)
        {
            long prod = i * i;
            if (x > xf)
            {
                break;
            }
            if (prod > y)
            {
                x = i;
                y = y + prod;
                c++;
            }
        }
        cout << (c - 1) << endl;
    }
    return 0;
}