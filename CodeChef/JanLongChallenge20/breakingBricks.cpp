#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a[4], total = 0;
        for (int i = 0; i < 4; i++)
        {
            cin >> a[i];
            if (i > 0)
                total += a[i];
        }
        int str = a[0];
        int count = 0;
        if (str >= total)
        {
            count = 1;
        }
        else
        {
            while (total > 0)
            {
                if (str < total)
                {
                    total = total - str;
                    count++;
                }
                else
                {
                    count++;
                    break;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}