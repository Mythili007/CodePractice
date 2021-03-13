/**
 * https://leetcode.com/problems/reverse-vowels-of-a-string/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        string v, res;
        // transform(s.begin(), s.end(), s.begin(), ::tolower);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
                v += s[i];
        }
        int j = v.size() - 1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'o' || s[i] == 'i' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
            {
                res += v[j];
                j--;
            }
            else
            {
                res += s[i];
            }
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string s = "hello";
    s = "leetcode";
    s = "aA";
    string res = sol.reverseVowels(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}