#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long int a, b, res;
        cin >> a >> b;

        if (b > 0)
        {
            if (a < b)
            {
                cout << "cannot distribute" << endl;
            }
            else
            {
                res = a / b;
                cout << res << endl;
            }
        }
    }

    return 0;
}