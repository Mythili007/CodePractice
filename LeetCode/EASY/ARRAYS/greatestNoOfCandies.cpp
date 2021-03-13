#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, l; //n=4,k=3, l=2
        cin >> n >> k >> l;
        int max = (n % k == 0) ? (n % k) : ((n % k) + 1);
        if (n / k > l || (k == 1 && n > 1))
        {
            cout << "-1";
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cout << (i % k) + 1 << " ";
            }
        }
        cout << endl;
    }
    return 0;
}