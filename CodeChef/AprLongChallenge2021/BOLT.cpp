#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        double k1, k2, k3, v;
        cin >> k1 >> k2 >> k3 >> v;
        double res = k1 * k2 * k3 * v;
        double _res = 100 / res;
        if (_res < 9.575)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        cout << endl;
    }
    return 0;
}