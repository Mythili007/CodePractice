#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string st, st1 = "";
        int n = 0;
        cin >> st;
        st1 = st;
        
        char ch[st.length() + 1];
        strcpy(ch, st.c_str());
        bool isHappy = true;

        n = atoi(st1.c_str());

        if (n % 21 == 0)
        {
            for (int i = 0; i < st.length(); i++)
            {
                for (int j = i + 1; j < st.length(); j++)
                {
                    if (ch[i] == '2' && ch[j] == '1')
                    {
                        isHappy = false;
                    }
                }
            }
        } else {
            isHappy = false;
        }
        if (isHappy)
            cout << "The streak lives still in our heart!" << endl;
        else
            cout << "The streak is broken!" << endl;
    }
    return 0;
}