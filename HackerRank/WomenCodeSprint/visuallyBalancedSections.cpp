#include <bits/stdc++.h>
using namespace std;

int visuallyBalancedSections(vector<int> v)
{
    stringstream ss;
    copy( v.begin(), v.end(), ostream_iterator<int>(ss, " "));
    string s = ss.str();
    s = s.substr(0, s.length()-1);

    map<string, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (!s[i + j])
                break;

            if (s[i - j] == s[i + j])
            {
                if ((i + j + 1) - (i - j) > 1)
                {
                    if ((i + j + 1) - (i - j) > 1) 
                    m[s.substr(i - j, (i + j + 1) - (i - j))]++;
                }
            }
            else
            {
                break;
            }
        }

        for (int j = 0; j <= i; j++)
        {
            if (!s[i + j + 1])
                break;
            if (s[i - j] == s[i + j + 1])
            {

                if ((i + j + 2) - (i - j) > 1) 
                    m[s.substr(i - j, (i + j + 2) - (i - j))]++;
            }
            else
                break;
        }
    }
    return m.size();
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int x;
        vector<int> colors;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            colors.push_back(x);
        }
        int count = visuallyBalancedSections(colors)+colors.size()-1;
        cout<<count<<endl;
    }
    return 0;
}