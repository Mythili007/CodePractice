
/**
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool palindromeChecker(string str, int start, int end)
    {
        if (start == end)
            return true;
        if (str[start] != str[end])
            return false;

        if (start < end + 1)
            return palindromeChecker(str, start + 1, end - 1);
        return true;
    }

    bool isPalindrome(string str)
    {
        if (str.size() <= 1)
            return true;

        return palindromeChecker(str, 0, str.size() - 1);
    }
};

void _main()
{
    Solution sol;
    string st = "malayalam";
    bool res = sol.isPalindrome(st);
    cout << res << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}