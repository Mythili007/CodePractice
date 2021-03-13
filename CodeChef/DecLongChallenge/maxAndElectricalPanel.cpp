#include <bits/stdc++.h>
using namespace std;

void formalSearch(int coins, int l, int r)
{
    int input;
    for (int i = l; i <= r; i++)
    {
        cout << "1 " << i << endl;
        cin >> input;
        if (input == 1)
        {
            cout << "3 " << i << endl;
            cout << flush;
            break;
        }
        coins--;
    }
}

int checkres(int mid)
{
    int z;
    cout << "1 " << mid << endl;
    cin >> z;
    return z;
}

int main()
{
    int n, c, y, x, z;
    cin >> n >> c;
    int coins = 1000;
    int l = 1;
    int r = n;
    int mid;
    if (coins >= n)
    {
        formalSearch(coins, l, r);
    }
    else
    {
        while (coins > 0)
        {
            mid = (l + r) / 2;
            cout << "mid: " << mid << " left: " << l << " right: " << r << " coins left: " << coins << " n: " << n << endl;
            if (n < coins)
            {
                formalSearch(coins, l, r);
                break;
            }
            int res = checkres(mid);
            if (res == 1)
            {
                cout << "2" << endl;
                r = mid - 1;
                // n = (l + r);
                coins = coins - c;
            }
            else
            {
                l = mid + 1;
                coins--;
            }
            n = (r - l);
        }
        // if (coins < c)
        // {
        //     cout << "3 " << mid << endl;
        //     cout << flush;
        // }
    }
    return 0;
}