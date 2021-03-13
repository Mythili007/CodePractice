/**
 * https://leetcode.com/problems/thousand-separator/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string thousandSeparator(int n)
    {
        string st = to_string(n);
        int cnt = 0;
        string res, s;
        for (int i = st.size() - 1; i >= 0; i--)
        {
            res += st[i];
            cnt++;
            if (cnt == 3 && i != 0)
            {
                res += '.';
                cnt = 0;
            }
        }
        cout<<"res: "<<res<<endl;
        for (int i = res.size() - 1; i >= 0; i--)
            s += res[i];
        return s;
    }
};

void _main()
{
    Solution sol;
    int n = 8971;
    n = 123456789;
    string res = sol.thousandSeparator(n);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}