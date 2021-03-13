/**
 * https://leetcode.com/problems/valid-palindrome-ii/
 * 
  */

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

class Solution
{
public:
    Solution()
    {
        FAST_IO
    }
    int LOW, HIGH;
    bool isValid(string s, int low, int high)
    {
        LOW = low;
        HIGH = high;
        while (low < high)
        {
            if (s[low] != s[high])
                return false;
            low++;
            high--;
            LOW = low;
            HIGH = high;
        }
        return true;
    }

    bool validPalindrome(string s)
    {
        if (isValid(s, 0, s.size() - 1))
        {
            return true;
        }
        int _low = LOW, _high = HIGH;
        return (isValid(s, _low + 1, _high)) || (isValid(s, _low, _high - 1));
    }
};

void _main()
{
    Solution sol;
    string s = "aba";
    s = "abc";
    // s = "deeee";

    bool res = sol.validPalindrome(s);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}