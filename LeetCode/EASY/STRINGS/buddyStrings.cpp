/**
 * https://leetcode.com/problems/buddy-strings/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //BRUTE FORCE APPROACH - TLE
    bool buddyStrings1(string A, string B)
    {
        string res = A;
        char temp;
        // if((A.size() == 0 && B.size() > 0) || (A.size() > 0 && B.size() == 0)) return false;
        for (int i = 0; i < A.size(); i++)
        {
            // res = A;
            for (int j = i + 1; j < A.size(); j++)
            {
                res = A;
                if (i != j && res[i] != res[j])
                {
                    temp = res[i];
                    res[i] = res[j];
                    res[j] = temp;
                    // cout << "res: " << res << endl;
                    if (res == B)
                        return true;
                }
            }
        }

        return false;
    }
    //SOLUTION FROM LEETCODE
    bool buddyStrings2(string A, string B)
    {
        int m = A.size(), n = B.size();
        if (m != n)
            return false;
        if (A == B)
        {
            int ch[26];
            for (int i = 0; i < 26; i++)
                ch[A[i] - 'a']++;

            for (int c : ch)
                if (c > 1)
                    return true;

            return false;
        }
        else
        {
            int first = -1, second = -1;
            for (int i = 0; i < m; i++)
            {
                if (A[i] != B[i])
                {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }

            return (second != -1 && A[first] == B[second] && A[second] == B[first]);
        }
    }
    //SOLUTION FROM DISCUSSIONS
    bool buddyStrings(string A, string B)
    {
        if (A.length() != B.length())
            return false;
        if (A == B && set<char>(A.begin(), A.end()).size() < A.size())
            return true;
        vector<int> dif;
        for (int i = 0; i < A.length(); ++i)
            if (A[i] != B[i])
                dif.push_back(i);
        return dif.size() == 2 && A[dif[0]] == B[dif[1]] && A[dif[1]] == B[dif[0]];
    }
};

void _main()
{
    Solution sol;
    string A = "aaabc";
    string B = "aaacb";
    A = "", B = "ab";
    A = "aaaaaaabc", B = "aaaaaaacb";
    A = "ab", B = "ab";
    bool res = sol.buddyStrings(A, B);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}