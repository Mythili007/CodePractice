/**
 * https://leetcode.com/problems/valid-palindrome-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPalindrome2(string s)
    {
        unordered_map<char, int> m;
        int n = s.size();
        char ch;
        string rev = "", res = "";
        if (n % 2 == 0)
        {
            for (int i = 0; i < n; i++)
                m[s[i]]++;

            for (auto a : m)
            {
                if (a.second == 1)
                {
                    ch = a.first;
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (s[i] != ch)
                {
                    res += s[i];
                }
            }
            cout << "res: " << res << endl;
            for (int i = n - 1; i >= 0; i--)
            {
                rev += res[i];
            }
        }
        cout << "rev: " << rev << " n: " << n << "  rev == res: " << (rev == res) << endl;
        if (n % 2 != 0)
        {
            for (int i = n - 1; i >= 0; i--)
            {
                rev += s[i];
            }
        }
        if (rev == s || rev == res)
            return true;
        else
            return false;
    }

    bool validPalindrome1(string s)
    {
        string res, r;
        int n = s.size(), c = 1;
        for (int i = n - 1; i >= 0; --i)
        {
            r += s[i];
        }
        if (r == s)
        {
            return true;
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                res += s[i];
            }
            int j = res.size() - 1;
            for (int i = 0; i < n; i++)
            {
                if (res[j] == s[i])
                {
                    j++;
                }
                else
                {
                    c++;
                }
                if (c > 1)
                    return false;
            }
            return true;
        }
    }
    //SOLUTION FROM GFG: https://www.geeksforgeeks.org/remove-character-string-make-palindrome/
    bool isPalindrome(string::iterator low, string::iterator high)
    {
        while (low < high)
        {
            if (*low != *high)
                return false;
            low++;
            high--;
        }
        return true;
    }
    int validPalindrome_1(string s)
    {
        int low = 0, high = s.size() - 1, idx = 0;
        while (low < high)
        {
            if (s[low] == s[high])
            {
                low++;
                high--;
            }
            else
            {
                if (isPalindrome(s.begin() + low, s.begin() + high))
                    return low;
                if (isPalindrome(s.begin() + low, s.begin() + high - 1))
                    return high;

                return -1;
            }
        }
        return -2;
    }

    bool validPalindrome(string s)
    {
        int idx = validPalindrome_1(s);
        if (idx == -1)
            return false;

        return true;
    }
};

void _main()
{
    Solution sol;
    string s = "aba";
    s = "abcda";
    s = "deeee";

    bool res = sol.validPalindrome(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}