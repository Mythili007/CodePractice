/**
 * https://leetcode.com/problems/determine-if-string-halves-are-alike/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    bool halvesAreAlike(string s)
    {
        int left = 0, right = s.size() - 1, left_cnt = 0, right_cnt = 0;
        while (left < right)
        {
            if (isVowel(s[left]))
                left_cnt++;

            if (isVowel(s[right]))
                right_cnt++;
            
            left++;
            right--;

            if (left == right)
                break;
        }
        return left_cnt == right_cnt;
    }

    bool halvesAreAlike_1(string s)
    {
        int x = 0, y = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (i < s.length() / 2)
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
                    x++;
            }
            else
            {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
                    y++;
            }
        }

        /* for (int i = s.length() / 2; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'O' || s[i] == 'I' || s[i] == 'U')
                y++;
        } */
        if (x == y)
            return true;
        else
            return false;
    }
};

void _main()
{
    Solution sol;
    string s = "textbok";
    int res = sol.halvesAreAlike(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}