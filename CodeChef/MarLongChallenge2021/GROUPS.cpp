#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    // t = 1;
    while (t--)
    {
        string st;
        // st = "0110101";
        cin >> st;

        int cnt = 0;
        for (int i = 0; i < st.size();)
        {
            if (st[i] == '1')
            {
                int j = i;
                while (st[j] != '0' && j < st.size())
                {
                    j++;
                }
                i = j;
                cnt++;
            }
            else
            {
                i++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

/* int main()
{

    int t;
    // cin >> t;
    t = 1;
    while (t--)
        return _main();

} */
