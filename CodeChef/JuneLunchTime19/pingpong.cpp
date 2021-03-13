#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int x, y, k;
        cin >> x >> y >> k;
        int res = (x + y) % k;

        if (res % 2 == 0)
            cout << "Chef" << endl;
        else
            cout << "Paja" << endl;
    }
    return 0;
}