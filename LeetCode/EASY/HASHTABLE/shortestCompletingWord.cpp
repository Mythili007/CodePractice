/**
 * https://leetcode.com/problems/shortest-completing-word/
 * Shortest Completing word
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words)
    {
        string res;
        unordered_map<char, int> um;
        char c;
        for (int i = 0; i < licensePlate.size(); i++)
        {
            c = licensePlate[i];
            if (isalpha(c) && isupper(c))
            {
                c = c + 32;
            }
            if (!isdigit(c) && c != ' ')
                um[c]++;
        }

        // for(auto i: um)
        //     cout<<"first: "<<i.first<<"  second: "<<i.second<<endl;

        int m = INT_MAX;
        for (string word : words)
        {
            bool isValid = true;
            unordered_map<char, int> checkFreq;
            for (char ch : word) //steps
            {
                cout<<"ch: "<<ch<<endl;
                if (um.find(ch) != um.end())
                    checkFreq[ch]++;
                // else
                // {
                //     isValid = false;
                    // break;
                // }
            }
            for (char ch : word)
            {
                if (um.find(ch) == um.end() && checkFreq[ch] < um[ch])
                {
                    isValid = false;
                    break;
                }
            }
            cout<<"isValid: "<<isValid<<endl;
            if (isValid)
            {
                cout<<"word: "<<word.size()<<endl;
                if (word.size() < m)
                {
                    res = "";
                    m = word.size();
                    res += word;
                }
            }
            // cout<<"res: "<<res<<endl;
            cout<<endl;
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string licensePlate = "1s3 PSt";
    vector<string> words = {"step", "steps", "stripe", "stepple"};
    licensePlate = "1s3 456", words = {"looks","pest","stew","show"};
    licensePlate = "Ah71752", words = {"suggest","letter","of","husband","easy","education","drug","prevent","writer","old"};
    // b = "cbb";
    string res = sol.shortestCompletingWord(licensePlate, words);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}