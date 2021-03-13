#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin >> n >> k;
        int a[n], sum = 0, ex = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > k)
            {
                ex += (a[i] - k);
            }
        }
        cout << ex << endl;
    }
    return 0;
}