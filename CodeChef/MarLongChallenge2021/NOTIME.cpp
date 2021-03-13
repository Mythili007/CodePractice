#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, h, x;
    cin >> n >> h >> x;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int flag = 0;
    for (int i : arr)
    {
        if (i + x >= h)
        {
            flag = 1;
            break;
        }
    }
    (flag == 1) ? cout << "YES" << endl : cout << "NO" << endl;
    return 0;
}
