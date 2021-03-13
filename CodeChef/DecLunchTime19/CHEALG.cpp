#include <bits/stdc++.h>
#include <iostream>
#include <sstream> // for string streams
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        string res = "";
        int l1 = s.length();
        int count = 0, i = 0, j = 0;
        if (l1 == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            for (i = j; i < l1; i++)
            {
                count = 1;
                for (j = i + 1; j < l1; j++)
                {
                    if (s[i] == s[j])
                    {
                        count++;
                    }
                    else
                    {
                        ostringstream str1;
                        str1 << count;
                        string c = str1.str();
                        res += s[i] + c;
                        i = j - 1;
                        break;
                    }
                }
                if (i == l1 - 1)
                {
                    ostringstream str1;
                    str1 << count;
                    string c = str1.str();
                    res += s[i] + c;
                }
            }
            if (res.length() < l1)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}