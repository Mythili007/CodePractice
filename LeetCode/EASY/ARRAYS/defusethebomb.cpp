/**
 * https://leetcode.com/problems/defuse-the-bomb/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sumOfNextNums(vector<int> &code, int k)
    {
        int sum = 0;
        vector<int> res(code.size());
        for (int i = 0; i < code.size(); i++)
        {
            sum = 0;
            for (int j = 1; j <= k; j++)
            {
                int c = i + j;
                cout << "c: " << c << endl;
                c = c % code.size();
                sum += code[c];
            }
            res[i] = sum;
        }
        return res;
    }

    vector<int> replaceWithZeros(vector<int> &code, int k)
    {
        int sum = 0, c = 0;
        vector<int> res(code.size());
        //replace all elements with 0
        for (int i = 0; i < code.size(); i++)
        {
            res[i] = 0;
        }
        return res;
    }

    vector<int> sumOfPrevNums(vector<int> &code, int k)
    {
        int sum = 0;
        vector<int> res(code.size());
        //sum of previous k nums is current num
        for (int i = 0; i < code.size(); i++)
        {
            sum = 0;
            for (int j = -1; j >= k; j--)
            {
                int c = i + j;
                if (c < 0)
                    c += code.size();
                sum += code[c];
            }
            res[i] = sum;
        }
        return res;
    }

    vector<int> decrypt(vector<int> &code, int k)
    {
        vector<int> res;
        if (k > 0)
            res = sumOfNextNums(code, k);
        else if (k == 0)
            res = replaceWithZeros(code, k);
        else
            res = sumOfPrevNums(code, k);
        return res;
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {5, 7, 1, 4};
    int k = 3;
    a = {2, 4, 9, 3}, k = -2;
    vector<int> res = sol.decrypt(a, k);
    for (int i : res)
    {
        cout << i << " ";
    }

    cout << endl;
}

int main()
{
    _main();
    return 0;
}