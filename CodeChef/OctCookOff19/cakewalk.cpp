#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n, amt = 1, rem = 0;
        cin >> n;
        int a = 100, b = 200, flag = 0;

        if (n == 10 || n == 20 || n == 100 || n == 200 || n == 400)
            cout << "yes" << endl;
        else if (n > 10 && n < 100)
        {
            cout << "No" << endl;
        }
        else if (n > 400)
        {
            while (n > 10)
            {
                rem = n % 10;
                if (rem != 0)
                {
                    flag = 1;
                    break;
                }
                n = n / 10;
            }
            if (flag == 1)
            {
                cout << "No" << endl;
            }
            else
            {
                cout << "Yes" << endl;
            }
        }
    }
    return 0;
}