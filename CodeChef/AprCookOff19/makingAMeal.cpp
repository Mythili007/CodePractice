#include <bits/stdc++.h>
// #include<iostream>
// #include<vector>
using namespace std;

int minNo(vector<int> v)
{
    int min = INT_MAX;
    // return std::min_element(v.begin(), v.end());
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < min)
            min = v[i];
    }

    return min;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string str;
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            str += s;
        }
        // cout << "str: " << str << endl;
        char ch[str.length()];
        strcpy(ch, str.c_str());
        int cCount = 0, oCount = 0, dCount = 0, eCount = 0, hCount = 0, fCount = 0;
        for (int i = 0; i < str.length(); i++)
        {
            if (ch[i] == 'c')
                cCount++;
            else if (ch[i] == 'o')
                oCount++;
            else if (ch[i] == 'd')
                dCount++;
            else if (ch[i] == 'e')
                eCount++;
            else if (ch[i] == 'h')
                hCount++;
            else if (ch[i] == 'f')
                fCount++;
        }

        cCount = cCount / 2;
        eCount = eCount / 2;

        vector<int> v;
        v.push_back(cCount);
        v.push_back(eCount);
        v.push_back(oCount);
        v.push_back(dCount);
        v.push_back(hCount);
        v.push_back(fCount);

        int res = minNo(v);

        cout << res << endl;
    }
    return 0;
}