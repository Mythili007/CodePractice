#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> v;
    map<int, vector<int>> m;
    vector<int> ff;
    int validate(vector<int> arr)
    {
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                vector<int> res;
                for (int k = i; k <= j; k++)
                {
                    res.push_back(arr[k]);
                }
                v.push_back(res);
            }
        }

        for (vector<int> i : v)
        {
            sort(i.begin(), i.end());
            if()
            /* if (i.size() >= 2)
            {
                int j = i.size() - 1;
                int cost = 0;
                if (i[j] != i[j - 1])
                    cost = i[j] - i[j - 1];

                ff.push_back(cost);
            } */
        }
    }
    int cnt = 0;
    for (int i = 1; i < ff.size(); i++)
    {
        if (ff[i - 1] != ff[i])
            cnt++;
    }
    return cnt;
}

int
maxSize(vector<int> arr)
{
    int res = validate(arr);
    return res;
}
}
;

int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int c;
            cin >> c;
            arr.push_back(c);
        }
        int res = sol.maxSize(arr);
        cout << res;
    }
    return 0;
}
