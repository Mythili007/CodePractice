#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n;
        cin >> n;
        lli i=1, d1 = 0, d2 = 0, sum = 0;
        while (1)
        {
            if (n - pow(2, (i - 1)) > 0)
            {
                d2 = i;
            }
            sum = sum - pow(2, (i - 1)) + n;

            if (sum < 0)
            {
                d1 = i - 1;
                break;
            }
            i++;
        }
        cout << d1 << " " << d2 << endl;
    }
    return 0;
}