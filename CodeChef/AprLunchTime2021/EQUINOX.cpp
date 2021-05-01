#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long int n, a = 0, b = 0, s1 = 0, s2 = 0;
        cin >> n >> a >> b;
        vector<string> ss;
        for (int i = 0; i < n; i++)
        {
            string st;
            cin >> st;
            ss.push_back(st);
        }

        for (string st : ss)
        {
            if (st[0] == 'E' || st[0] == 'Q' || st[0] == 'U' || st[0] == 'I' ||
                st[0] == 'N' || st[0] == 'O' || st[0] == 'X')
                s1 += a;
            else
                s2 += b;
        }
        if (s1 > s2)
            cout << "SARTHAK" << endl;
        else if (s1 < s2)
            cout << "ANURADHA" << endl;
        else
            cout << "DRAW" << endl;
        cout << endl;
    }
    return 0;
}