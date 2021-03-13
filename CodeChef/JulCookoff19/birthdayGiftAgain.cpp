#include <bits/stdc++.h>
using namespace std;

bool isSpecialStr(string str, int len)
{
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }

    if (cnt0 == cnt1 * cnt1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int cnt0 = 0, cnt1 = 0, count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 1; j <= s.length() - i; j++)
            {
                string ss = s.substr(i, j);
                if (isSpecialStr(ss, ss.length()))
                {
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}