#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long int n;
        cin >> n;
        long long int a[n], negCount = 0, posCount = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] > 0)
            {
                posCount++;
            }
            else
            {
                negCount++;
            }
        }
        if (posCount == n)
            cout << n << " " << n << endl;
        else
            cout << posCount << " " << negCount << endl;
    }
    return 0;
}