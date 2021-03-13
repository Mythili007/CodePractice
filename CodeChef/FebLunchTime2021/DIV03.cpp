#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        vector<int> v;
        int a;
        for (int i = 0; i < 10; i++)
        {
            cin >> a;
            v.push_back(a);
        }
        int k;
        cin >> k;
        for (int i = 9; i >= 0; i--)
        {
            if (v[i] > 0)
            {
                if (k >= v[i])
                {
                    k = k - v[i];
                    v[i] = 0;
                }
                else
                {
                    k = v[i] - k;
                    v[i] = k;
                }
            }
            // cout << "k: " << k << "    v[i]: " << v[i] << endl;
            if (k == 0)
                break;
        }
        cout << endl;
        for (int i = 9; i >= 0; i--)
        {
            // cout << v[i] << " ";
            if (v[i] > 0)
            {
                cout << i + 1 << endl;
                break;
            }
        }

        cout << endl;
    }
    return 0;
}