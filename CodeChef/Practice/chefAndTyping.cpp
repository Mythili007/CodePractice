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
        string s, s1 = "";
        int sum = 2, val = 0, sum1 = 0;
        vector<string> str1;
        vector<int> str2;
        for (int i = 0; i < n; i++)
        {
            cin >> s;
            int flag = 0;
            for (int j = 0; j < i; j++)
            {
                if (s == str1[j])
                {
                    str2.push_back(str2[j] / 2);
                    flag = 1;
                    break;
                }
            }
            // str1.push_back(s);
            if (flag == 0)
            {
                sum = 2;
                for (int l = 1; l < s.length(); l++)
                {
                    if (s[l - 1] == s[l] || (s[l] == 'd' && s[l - 1] == 'f') || (s[l] == 'f' && s[l - 1] == 'd') || (s[l] == 'j' && s[l - 1] == 'k') || (s[l] == 'k' && s[l - 1] == 'j'))
                    {
                        sum+=4;
                    } else {
                        sum+=2;
                    }
                }
                str2.push_back(sum);
            }
            str1.push_back(s);
        }

        for(int i=0;i<str2.size();i++){
            sum1+=str2[i];
        }

       
        cout << "sum1: " << sum1 << endl;
    }
    return 0;
}