#include <bits/stdc++.h>
using namespace std;

int main()
{
    double t, x1, x2, x3, v1, v2, d1, d2;
    cin >> t;
    while (t--)
    {
        cin >> x1;
        cin >> x2;
        cin >> x3;
        cin >> v1;
        cin >> v2;
        d1 = abs(x1 - x3) / v1;
        d2 = abs(x2 - x3) / v2;
        // cout << "d1: " << d1 << " d2 : " << d2 << endl;
        if (d1 < d2)
        {
            cout << "Chef" << endl;
        }
        else if (d1 > d2)
        {
            cout << "Kefa" << endl;
        }
        else if (d1 == d2)
        {
            cout << "Draw" << endl;
        }
    }
    return 0;
}