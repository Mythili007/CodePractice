#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long int k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        lli a = 0, b = 0, c = 0;
        for (lli i = 0; i <= k - 1; i++)
        {
            a = arr[i % n];
            b = arr[n - (i % n) - 1];
            // c = a^b;

            arr[i % n] = a ^ b;
        }

        for (int j = 0; j < n; j++)
        {
            cout << arr[j] << " ";
        }
        cout << endl;
    }
    return 0;
}