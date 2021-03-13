#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int count = 0, rem = 0;
        for (int i = 1; i <= n; i++)
        {
            // rem = n-i;
            // cout << "i: " << i << endl;
            // while (rem != 0)
            // {
            rem = n - i;
            // cout << "rem: " << rem << endl;
            count++;
            n = rem;
            // }
        }
        cout << count << endl;
    }
    return 0;
}
