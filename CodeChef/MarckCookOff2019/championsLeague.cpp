#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n = 12;
        string st;
        for (int i = 0; i < 1; i++)
        {
        //     char ch[100];
        // scanf("%[^\n]%*c", ch);
        // string s(ch);

        // string arr[100];
        // stringstream ssin(s);
        // while (ssin.good())
        // {
        //     ssin >> arr[i];
        // }
            cin >> st;
            vector<string> result;
            stringstream iss(st);
            string word;
            while (iss >> word)
            {
                cout << word << endl;
            }
        }
    }
    return 0;
}