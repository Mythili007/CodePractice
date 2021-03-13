#include <bits/stdc++.h>
using namespace std;

string productName(vector<string> names)
{
    string s = "zzzzz";
    for (int i = 0; i < names.size(); i++)
    {
        string s1 = names[i];
        if (s1[0] == s[0])
        {
            s[0] = s[0] - 'a';
        }
        if (s1[1] == s[1])
        {
            s[1] = s[1] - 'a';
        }
        if (s1[2] == s[2])
        {
            s[2] = s[2] - 'a';
        }
        if (s1[3] == s[3])
        {
            s[3] = s[3] - 'a';
        }
        if (s1[4] == s[4])
        {
            s[4] = s[4] - 'a';
        }
    }
    return s;
}

int main()
{
    int n;
    vector<string> names;
    string x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        names.push_back(x);
    }
    // string res = productName(names);
    // cout<<"res: "<<res<<endl;
    string a = "zzzzz";
    char ch = a[0]-'a';
    cout<<ch<<endl;
    return 0;
}