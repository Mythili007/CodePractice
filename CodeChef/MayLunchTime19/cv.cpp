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
        string st, str = "aeiou";
        cin >> st;
        int count = 0, flag = 0;
        for (int i = 0; i < n; i++)
        {
            /*  if((st[i]!='a' || st[i]!='e' || st[i]!='i' || st[i]!='o' || st[i]!='u') && (st[i+1]=='a' || st[i+1]=='e' || st[i+1]=='i' || st[i+1]=='o' || st[i+1]=='u')){
                count++;
                i++;
            } */
            flag = 0;
            for (int j = 0; j < 5; j++)
            {
                if (st[i] == str[j])
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                for (int j = 0; j < 5; j++)
                {
                    if (st[i + 1] == str[j])
                    {
                        count++;
                        break;
                    }
                }
            }
        }
        cout << count << endl;
    }

    return 0;
}