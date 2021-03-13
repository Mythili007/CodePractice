#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n, a, b, k, count1 = 0;
        cin >> n >> a >> b >> k;
        
        lli lcm = (a*b)/__gcd(a,b);
        
        lli commMultipleCount = (n/lcm) - (1/lcm);

        count1 = (n / a) + (n / b) - 2*commMultipleCount;

        if (count1 >= k)
        {
            cout << "Win" << endl;
        }
        else
        {
            cout << "Lose" << endl;
        }
    }
    return 0;
}