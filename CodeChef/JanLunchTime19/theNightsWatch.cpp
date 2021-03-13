#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        long long int n;
        cin >> n;
        string st;
        cin >> st;
        // long long int res = n/2;
        // cout << res << endl;
        char ch[n];
        strcpy(ch, st.c_str());

        //Subtask1 - Initially all towers are empty - string conatins only 0s
        // int count = maxNoOfNightsWatchCanBePlaced(ch, n);
        int count = 0;
        if (n != 1)
        {
            if (ch[0] == '0' && ch[1] == '0')
            {
                count++;
                ch[0] = '1';
            }
            for (int i = 1; i < n - 1; i++)
            {
                if (ch[i] != '1' && ch[i + 1] !='1'  && ch[i - 1] != '1')
                {
                    count++;
                    ch[i] = '1';
                }
            }

            if (ch[n - 2] == '0' && ch[n - 1] == '0')
            {
                count++;
            }
            // if(count%2==0){
            //     count=count/2;
            // } else {
            //     count = (count/2)+1;
            // }
            cout << count << endl;
        }
    }
    return 0;
}
