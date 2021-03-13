#include <bits/stdc++.h>
using namespace std;
#define max(a, b) ((a > b) ? (a) : (b))

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int p[n], s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> p[i] >> s[i];
        }
        int max_score = INT_MIN, sum = 0, m = 0, c = 0;
        for (int i = 0; i < n; i++)
        {
            max_score = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (p[i] <= 8)
                {
                    if (p[i] == p[j])
                    {
                        c++;
                        cout << "p[i]: " << p[i] << " p[j]: " << p[j] << endl;
                        max_score = max(s[i], s[j]);
                        if (max_score > m)
                        {
                            m = max_score;
                        }
                        cout << "max: " << m << endl;
                    }
                }
            }
            sum += m;
            if (c == n - 1)
            {
                break;
            }
            // cout << "max_score " << max_score << endl;
        }
        cout << sum << endl;
    }
    return 0;
}