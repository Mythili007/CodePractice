#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string decodeit(int N, string s)
    {
        string st = "abcdefghijklmnop";
        int left = 0, right = s.length() - 1;
        string res = "";
        for (int i = 0; i < N; i += 4)
        {
            if (s[i] == '0')
            {
                left = 0;
                right = 7;
            }
            else
            {
                left = 8;
                right = 15;
            }
            for (int j = i + 1; j < N; j++)
            {
                if (s[j] == '0')
                {
                    right = (left + right) / 2;
                }
                else
                {
                    left = ((left + right) / 2) + 1;
                }

                if (left == right)
                {
                    res += st[left];
                    break;
                }
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N;
        cin >> N;
        string s;
        cin >> s;
        string res = sol.decodeit(N, s);
        cout << res << endl;
    }
}

int main()
{
    _main();
    return 0;
}