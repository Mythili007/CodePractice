#include <bits/stdc++.h>
using namespace std;
// #define mod (10^9+7)
#define MOD 1000000007
// #define unsigned long ul

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        unsigned long l, r;
        cin >> l >> r;
        unsigned long sum = l;
        for (unsigned long i = l+1; i <= r; i++)
        {
            cout<<"i: "<<i<<endl;
            // sum = i+(i&(i+1))+(i&(i+1)&(i+2))+....
            sum = sum + (sum&i);
            cout<<"sum: " <<sum<<endl;
            // sum = sum % MOD;
            //l-=1, r = 3.. sum = 0&1 = 1
        }
        sum = sum%MOD;
        cout << sum << endl;
    }
    return 0;
}