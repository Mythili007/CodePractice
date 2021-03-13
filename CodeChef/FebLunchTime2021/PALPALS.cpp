#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> v;
    vector<string> palin;
    void getSubStrings(string s)
    {
        for (int i = 0; i < s.length; i++)
        {
            string res;
            for (int j = 1; j < s.length - i; j++)
            {
                res += s.substr(i, j);
            }
            v.push_back(res);
        }
        return;
    }

    void palindromes(){
        for(string s:v){
            if(reverse(s.begin(), s.end()) == s)
                palin.push_back(s);
        }
    }

    void check(){
        //check for the repetition
    }

    bool isPalPalString(string st)
    {
        getSubStrings(st);
        check();
    }
};

int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t-- > 0)
    {
        string st;
        cin >> st;
        if (sol.isPalPalString(st))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        cout << endl;
    }
    return 0;
}
