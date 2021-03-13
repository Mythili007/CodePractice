#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        unsigned int n, k;
        cin >> n >> k;
        if (n > k)
        {
            while (n >= k)
            {
                n = n - k;
            }
            cout << n << endl;
        }
        else if (n == k)
            cout << "0" << endl;
        else
            cout << n << endl;
    }
    return 0;
}