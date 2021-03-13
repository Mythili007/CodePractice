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
        bool isPossible = true;
        if (st[0] == '0')
            cout << "NO" << endl;
        else
        {
            for (int i = 0; i < st.length(); i++)
            {
                for (int j = i + 1; j < st.length(); j++)
                {
                    if (st[i] == '*')
                    {
                        if (!st[i + 1] == '0' || !(st[i + 1] == '0' && st[i + 2] == '*') || !(st[i + 1] == '0' && st[i + 2] == '0' && st[i + 3] == '*'))
                        {
                            isPossible = false;
                        }
                    }
                    if (isPossible == false)
                        break;
                }
                if (isPossible == false)
                    break;
            }

            if (isPossible == false)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
    return 0;
}