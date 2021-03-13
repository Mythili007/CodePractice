#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        string st[n];
        cin >> n;

        vector<string> alice;
        vector<string> bob;
        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
        }
        int vC = 0, cC = 0;
        for (int i = 0; i < n; i++)
        {
            string s = st[i];
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u')
                {
                    vC++;
                }
                else
                    cC++;
            }
            if (vC > cC)
                alice.push_back(s);
            else
                bob.push_back(s);
        }

        for (int i = 0; i <= alice.size(); i++)
        {
            cout << "alice[i]" << alice[i] << endl;
        }
    }
    return 0;
}