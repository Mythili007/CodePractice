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
        int villiansStrengths[n];
        int playersStrengths[n];
        for (int i = 0; i < n; i++)
        {
            cin >> villiansStrengths[i];
        }

        for (int i = 0; i < n; i++)
        {
            cin >> playersStrengths[i];
        }

        sort(villiansStrengths, villiansStrengths + n);
        sort(playersStrengths, playersStrengths + n);
        int count = 0;

        for (int i = 0; i < n; i++)
        {
            if (playersStrengths[i] < villiansStrengths[i])
            {
                cout << "LOSE" << endl;
                break;
            }
            else
            {
                count++;
            }
        }
        if (count == n)
        {
            cout << "WIN" << endl;
        }
    }
}