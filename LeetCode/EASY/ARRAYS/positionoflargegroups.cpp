/**
 * https://leetcode.com/problems/positions-of-large-groups/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        // int sI = 0;
        // int eI = 0; //abbxxxxzyy
        // int c = 0;
        int start = 0;
        int end = 0;
        vector<int> a;
        vector<vector<int>> b;
        unordered_map<char, int> m;
        // int mx = 0;
        // char ch = ' ';
        // vector<char> ch;
        // vector<int> mx;
        for (int i = 0; i < s.length(); i++)
            m[s[i]]++;

        for (auto i : m)
        {
            cout << "i.first: " << i.first << "   i.second: " << i.second << endl;
            /* if (i.second >= 3)
            {
                // mx = i.second;
                ch.push_back(i.first);
                mx.push
            } */
        }
        for (int i =0;i<s.length();i++)
        {
            for (int j = i+1; j < s.length(); j++)
            {
                if(s[i] == s[j]){
                    c++;
                    if(c>=3){
                        
                    }
                }
                cout<<"j: "<<j<<endl;
                if (i.second >= 3 && s[j] == i.first)
                {
                    start = j;
                    end = start + i.second - 1;
                    cout<<"start: "<<start<<"    end: " <<end<<endl;
                    a.push_back(start);
                    a.push_back(end);
                    b.push_back(a);
                    break;
                }
            }
        }

        return b;
    }
};

void _main()
{
    Solution sol;
    string s = "abbxxxxzyy";
    s = "abcdddeeeeaabbbcd";
    vector<vector<int>> res = sol.largeGroupPositions(s);
    for (vector<int> i : res){
        for (int j : i)
            cout << j << " ";
        cout<<endl;
    }
        
    cout << endl;
}

int main()
{
    _main();
    return 0;
}