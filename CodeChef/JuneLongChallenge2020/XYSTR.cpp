#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string st;
        cin >> st;
        int c = 0, d = 0;
        for (int i = 0; i < st.length(); i++)
        {
            for (int j = i + 1; j < i + 2; j++)
            {
                if (st[i] == 'x' && st[j] == 'y')
                    c += 1;
                if (st[i] == 'y' && st[j] == 'x')
                    d += 1;
            }
        }
        if (c >= d)
            cout << c << endl;
        else
            cout << d << endl;
    }
    return 0;
}