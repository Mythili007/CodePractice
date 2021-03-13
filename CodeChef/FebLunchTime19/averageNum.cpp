#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k, v;
        cin >> n >> k >> v;
        int x, sum = 0, num;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            sum += num;
        }
        // cout << "sum: " << sum << endl;
        int res = ((v * (n + k)) - sum) / k;
        // cout << "(v * (n + k)): " << (v * (n + k)) << endl;
        // cout << "(sum * k): " << (sum * k) << endl;
        // cout << "res: " << res << endl;
        if (((v * (n + k)) - sum) % k == 0 && ((v * (n + k)) - sum) / k > 0)
        {
            x = res;
        }
        else
        {
            x = -1;
        }

        cout << x << endl;
    }
    return 0;
}