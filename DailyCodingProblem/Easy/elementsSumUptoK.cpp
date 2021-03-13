#include <bits/stdc++.h>
using namespace std;

int main()
{
    /* int n;
    cin >> n;
    int a[n]; // = {1, 2, 3, 4, 5};

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    } */

    int a[] = {10, 15, 3, 7}, k = 17, sum = 0;
    string flag = "false";
    for (int i = 0; i < 4; i++)
    {
        sum = 0;
        for (int j = i + 1; j < 4; j++)
        {
            sum = a[i] + a[j];
            if (sum == k)
            {
                flag = "true";
                break;
            }
        }
    }
    cout << flag << endl;
    return 0;
}