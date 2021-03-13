#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fairElections(int N, int M, vector<int> &a, vector<int> &b, int sum_b)
    {
        int c = 0, sum = 0, j = 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int k = b.size();

        while (sum < sum_b)
        {
            swap(a[j], b[k - 1]);
            c++;
            k--;
            j++;
            //to be continued
            sum = 0;
            for (int i = 0; i < N; i++)
            {
                sum += a[i];
            }
            sum_b = 0;
            for (int i = 0; i < M; i++)
            {
                sum_b += b[i];
            }

            if (sum > sum_b)
                break;
        }
        return c;
    }
};

void _main()
{
    Solution sol;
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int N, M;
        cin >> N >> M;
        int sum_a = 0, sum_b = 0, res = 0;
        vector<int> a;
        vector<int> b;
        for (int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            a.push_back(n);
            sum_a += n;
        }

        for (int i = 0; i < M; i++)
        {
            int m;
            cin >> m;
            b.push_back(m);
            sum_b += m;
        }
        if (sum_a <= sum_b)
            res = sol.fairElections(N, M, a, b, sum_b);
        cout << res << endl;
    }
}

int main()
{
    _main();
    return 0;
}