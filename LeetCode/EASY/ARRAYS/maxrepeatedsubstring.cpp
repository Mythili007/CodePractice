/**
 * https://leetcode.com/problems/maximum-repeating-substring/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //reference from discussions
    bool equal(const vector<int> &a, int begin, int end, int position)
    {
        while (begin < end)
        {
            cout << "a[begin]: " << a[begin] << "   a[position]: " << a[position] << endl;
            if (a[begin++] != a[position++])
                return false;
        }
        return true;
    }
    bool containsPattern(const vector<int> &arr, int m, int k)
    {
        for (int i = 0; i < arr.size() - m; ++i)
        {
            int c = 1;
            for (int j = i + m; j <= arr.size() - m; j += m)
            {
                cout << "j: " << j << endl;
                if (equal(arr, i, i + m, j))
                {
                    ++c;
                }
                else
                {
                    break;
                }

                if (c == k)
                {
                    return true;
                }
            }
        }
        return false;
    }

    int maxRepeating(string sequence, string word)
    {
        int m = sequence.length(), n = word.length(), c = 0;

        for (int i = 0; i < m; i++)
        {
            int x = 0, y = 0;
            for (int j = i; j < m; j++)
            {
                // string s = sequence.substr(i, j);
                // if (s == word)
                //     c++;
                if (sequence[j] == word[y])
                    y++;
                else
                    break;

                if (y == n)
                {
                    y=0;
                    x++;
                }
            }
            c = max(c, x);
        }
        return c;
    }
};

void _main()
{
    Solution sol;
    string st = "ababc", word = "ab";
    st = "aaabaaaabaaabaaaabaaaabaaaabaaaaba", word = "aaaba";

    int res = sol.maxRepeating(st, word);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}