#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        /* code */
        int n;
        cin >> n;
        string st;
        cin >> st;
        //PAPAPAPPP - 01 23 45 6 78
        float count = 0;
        for (int i = 0; i < n; i++)
        {
            if (st[i] == 'P')
                count++;
        }

        float crnt_att = count / n;
        
        int minProxyReq = 0;
        if (crnt_att >= 0.75)
        {
            cout << "0" << endl;
        }
        else
        {
            for (int i = 2; i <= n - 3; i++)
            {
                if (st[i] == 'A' && ((st[i - 2] == 'P' || st[i - 1] == 'P') && (st[i + 1] == 'P' || st[i + 2] == 'P')))
                {
                    count++;
                    minProxyReq++;
                }
                if (count / n >= 0.75)
                    break;
            }
            if (count / n >= 0.75)
                cout << minProxyReq << endl;
            else
                cout << "-1" << endl;
        }
    }

    return 0;
}