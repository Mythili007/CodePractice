#include <bits/stdc++.h>
using namespace std;

int subStringsWithMaxCount(string s)
{
    int len = s.length();
    string subStr;
    int max = INT_MIN;
    string prev, current;
    vector<string> v;
    for (int i = 0; i < 1; i++)
    {
        for (int j = 1; j <= len - i; j++)
        {
            subStr = s.substr(i, j);
            v.push_back(subStr);
            if (v.size() > 0)
            {
                prev = v[j - 1];
                current = subStr;
                cout<<"prev[prev.length() - 1: "<<prev[prev.length() - 1]<<endl;
                cout<<"subStr[0]: "<<subStr[0]<<endl;
                if (j>1 && subStr[0] == subStr[subStr.length()-1])
                {
                    break;
                }
                if (subStr.length() > max)
                {
                    max = subStr.length();
                }
                cout << "subStr: " << subStr << endl;
                cout << "subStr length: " << subStr.length() << endl;
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << "v[i]: " << v[i] << endl;
    }
    cout << "max: " << max << endl;
    return max;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string s1, s2;

        cin >> s1 >> s2;

        int subStrWithMaxCount_G = subStringsWithMaxCount(s1);
        int subStrWithMaxCount_A = subStringsWithMaxCount(s2);

        if (subStrWithMaxCount_G > subStrWithMaxCount_A)
        {
            cout << "AG" << endl;
        }
        else
        {
            cout << "AB" << endl;
        }
    }
    return 0;
}