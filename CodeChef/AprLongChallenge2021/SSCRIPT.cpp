#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N, K;
        cin >> N >> K;
        string s;
        cin >> s;
        int cnt = 0;
        bool flag = false;
        for (char ch : s)
        {
            if (ch == '*')
            {
                cnt++;
                if (cnt == K)
                {
                    flag = true;
                    break;
                }
            }
            else
                cnt = 0;
        }
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}