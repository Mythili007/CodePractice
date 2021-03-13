/**
 * https://leetcode.com/problems/unique-email-addresses/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        string p1, p2;
        vector<string> res;
        for (int i = 0; i < emails.size(); i++)
        {
            string email = emails[i];
            p1 = "";
            p2 = "";
            for (int j = 0; j < email.size(); j++)
            {
                if (email[j] == '+' || email[j] == '@')
                    break;
                else if (email[j] != '.')
                    p1 += email[j];
            }
            cout << "p1: " << p1 << endl;
            for (int j = 0; j < email.size(); j++)
            {
                if (email[j] == '@')
                    p2 += email.substr(j, email.size() - 1);
            }
            cout << "p2: " << p2 << endl;
            cout << "(p1+p2): " << (p1 + p2) << endl;
            res.push_back(p1 + p2);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res.size();
    }
};

void _main()
{
    Solution sol;
    vector<string> emails = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};
    int res = sol.numUniqueEmails(emails);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}