#include <bits/stdc++.h>
using namespace std;
#define li long int
#define lli long long int

string converter(int num)
{
    string res;
    while (num > 0)
    {
        if (num % 2 == 1)
            res += "1";
        else
            res += "0";
        num = num / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

lli convertBack(string s)
{
    lli x = 0, p = 1;
    for (lli i = s.size() - 1; i >= 0; i--)
    {
        x += ((s[i] - '0') * p);
        p = p * 2;
    }
    return x;
}

int main()
{
    int t;
    // cin >> t;
    t = 1;
    while (t--)
    {
        lli c = 10;
        // cin >> c;
        vector<bool> checker;
        string c_binary = converter(c);
        cout<<c_binary<<endl;
        /* for (int i = 0; i < c_binary.size(); i++)
        {
            if (c_binary[i] == '0')
                checker[i] = false;
            else
                checker[i] = true;
        } */
        bool flag = false;
        string a = "";
        string b = "";
        for (lli i = 0; i < c_binary.size(); i++)
        {
            if (c_binary[i] == '0')
            {
                a += '1';
                b += '1';
            }
            else
            {
                if (flag)
                {
                    a += '0';
                    b += '1';
                }
                else
                {
                    a += '1';
                    b += '0';
                    flag = true;
                }
            }
        }
        lli A = convertBack(a);
        lli B = convertBack(b);

        cout << A * B << endl;
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
