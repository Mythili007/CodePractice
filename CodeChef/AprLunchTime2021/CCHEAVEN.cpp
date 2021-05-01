#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int l;
        string s;
        cin >> l >> s;
        int cnt = 0;
        for (char ch : s)
        {
            if (ch == '1')
                cnt++;
        }
        int allowedCnt = l / 2;

        if (cnt >= allowedCnt)
            cout << "YES" << endl;
        else {
            string res;
            
        }
            cout << "NO" << endl;
    }
    return 0;
}