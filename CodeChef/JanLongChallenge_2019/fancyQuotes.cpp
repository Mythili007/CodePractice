#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    getchar();
    while (t-- > 0)
    {
        char ch[100];
        scanf("%[^\n]%*c", ch);
        string s(ch);
        bool fancy = false;

        string arr[100];
        int i = 0;
        stringstream ssin(s);
        while (ssin.good() && i < 100)
        {
            ssin >> arr[i];
            ++i;
        }
        
        string word = "";
        string ss = "not";
        for (i = 0; i < 100; i++)
        {
            word = arr[i];
            if (ss == word)
            {
                fancy = true;
                break;
            }
        }
        if (fancy)
        {
            cout << "Real Fancy" << endl;
        }
        else
        {
            cout << "regularly fancy" << endl;
        }
    }
    return 0;
}