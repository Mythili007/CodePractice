#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n], count = 0, i,j;
        string isGood = "true";
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= 5; j++)
            {
                if (a[i] >= a[j])
                    break;
            }
            if (j == i)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}