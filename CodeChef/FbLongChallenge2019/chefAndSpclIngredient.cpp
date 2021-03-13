#include <bits/stdc++.h>
using namespace std;
#define MAX_CHAR 26

void commonChar(vector<string> s, int n)
{
    int count = 0;
    bool init[MAX_CHAR];
    memset(init, true, sizeof(init));

    for (int i = 0; i < n; i++)
    {
        bool sec[MAX_CHAR] = {false};

        for (int j = 0; s[i][j]; j++)
        {
            if (init[s[i][j] - 'a'])
                sec[s[i][j] - 'a'] = true;
        }

        memcpy(init, sec, MAX_CHAR);
    }

    for (int i = 0; i < 26; i++)
    {
        if (init[i])
        {
            count++;
        }
    }
    cout << count << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;

        vector<string> st;
        string s;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            st.push_back(s);
        }
        // int size = sizeof(st)/sizeof(st[0]);
        // cout << "size: "<<size<<endl;
        commonChar(st, n);
    }
    return 0;
}