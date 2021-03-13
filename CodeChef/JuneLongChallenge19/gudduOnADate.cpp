#include <bits/stdc++.h>
#include <float.h>
using namespace std;
typedef unsigned long long int ulli;
typedef long long int lli;

ulli sumOfDigits(ulli num)
{
    ulli rem = 0;
    ulli sum = 0;
    while (num > 0)
    {
        rem = num % 10;
        sum += rem;
        num = num / 10;
    }
    return sum;
}

int main()
{
    // cout << ULLONG_MAX << endl;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        /* code */
        ulli n, res = 0, x = 0;
        cin >> n;
        ulli num = n;
        // cout<<"val: "<<num%n<<endl;
        int sum = sumOfDigits(n);
        if (sum % 10 == 0)
        {
            x = 0;
        }
        else
        {
            x = 10 - (sum % 10);
        }
        res = (num * 10) + (x);
        cout << res << endl;
    }
    return 0;
}