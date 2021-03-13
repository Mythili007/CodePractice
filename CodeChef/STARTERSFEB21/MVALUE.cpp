#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n = 0;
        cin >> n;
        long long int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        
        sort(arr, arr + n);
        // For positive and negative
        long long int res_1 = 0, res_2 = 0;
        res_1 = arr[0] * arr[1] + max(arr[0] - arr[1], arr[1] - arr[0]);
        res_2 = arr[n - 1] * arr[n - 2] + max(arr[n - 1] - arr[n - 2], arr[n - 2] - arr[n - 1]);
        if (res_1 > res_2)
            cout << res_1 << endl;
        else
            cout << res_2 << endl;
        cout << endl;
    }
    return 0;
}
