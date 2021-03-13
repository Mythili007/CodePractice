#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string s, r;
        cin >> s >> r;
        int cS0 = 0, cS1 = 0, cR0 = 0, cR1 = 0;

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '0')
            {
                cS0++;
            }

            else
                cS1++;
        }

        for (int i = 0; i < r.length(); i++)
        {
            if (r[i] == '0'){
                cR0++;
            }
            else{
                cR1++;
            }
        }
        // cout << "cs_0: " << cS0 << " cs_1: " << cS1 << " cr_0: " << cR0 << " cr_1: " << cR1 << endl;

        if (cS0 == cR0 && cS1 == cR1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        cS0 = 0, cS1 = 0, cR0 = 0, cR1 = 0;
    }
    return 0;
}