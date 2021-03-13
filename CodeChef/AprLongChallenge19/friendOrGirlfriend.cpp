#include <bits/stdc++.h>
using namespace std;

int countSubstringsContainsX(string st, char ch)
{
    int count = 0;
    int n = st.length();

    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "st.substr(i, j): " << st.substr(i, j) << endl;
            if (st.substr(i, j).find(ch) != std::string::npos)
                count++;
        }
    }
    return count;
}

int main()  
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int sum = 0;
        int n;
        cin >> n;
        string st;
        char x;
        cin >> st >> x;

        int count = countSubstringsContainsX(st, x);
        cout << count << endl;
    }
    return 0;
}