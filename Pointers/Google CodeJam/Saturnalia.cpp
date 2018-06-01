#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    freopen ("A-small-practice.in","r",stdin);
    int t = 1, j = 1;
    string str;
    cin >> t;
    // getline(cin, str);
    cin.ignore(1);
    while (j <= t)
    {
        getline(cin, str);
        cout << "Case #" << j << ":" << endl;
        cout << "+-";
        for (int i = 0; i < str.length(); i++)
        {
            cout << "-";
        }
        cout << "-+" << endl;
        cout << "| ";
        for (int i = 0; i < str.length(); i++)
        {
            cout << str[i];
        }
        cout << " |" << endl;
        cout << "+-";
        for (int i = 0; i < str.length(); i++)
        {
            cout << "-";
        }
        cout << "-+" << endl;
        j++;
    }
    return 0;
}