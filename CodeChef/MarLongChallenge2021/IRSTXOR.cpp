#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        long long int c;
        cin >> c;
        long long int prod = 0;
        // long long int a = c<<1;
        // cout<<"left shift: "<<a<<endl;
        //13 in powers of 2
        long long int val = 0, d = 0;
        while (true)
        {
            if (c < pow(2, d))
            {
                val = d;
                break;
            }
            else
                d++;
        }
        long long int limit = pow(2, val);
        for (long long int i = 0; i < limit; i++)
        {
            for (long long int j = i + 1; j < limit; j++)
            {
                long long int sum = (i ^ j);
                if (sum == c)
                    prod = max(prod, i * j);
            }
        }
        cout << prod << endl;
    }
    return 0;
}

/* int main()
{

    int t;
    // cin >> t;
    t = 1;
    while (t--)
        return _main();

} */
