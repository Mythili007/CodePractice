
/*
 * https://leetcode.com/problems/count-items-matching-a-rule/
 * 1773. Count Items Matching a Rule
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int cnt = 0;
        for (vector<string> item : items)
        {
            if (ruleKey == "type" && item[0] == ruleValue)
                cnt++;
            else if (ruleKey == "color" && ruleValue == item[1])
                cnt++;
            else if (ruleKey == "name" && ruleValue == item[2])
                cnt++;
        }
        return cnt;
    }
};

void _main()
{
    Solution sol;
    vector<vector<string>> items = {{"phone", "blue", "pixel"}, {"computer", "silver", "lenovo"}, {"phone", "gold", "iphone"}};
    string ruleKey = "color", ruleValue = "silver";

    int res = sol.countMatches(items, ruleKey, ruleValue);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}