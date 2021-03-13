#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findAndPushFactors(int num)
    {
        vector<int> v;
        for (int i = 1; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                if (num / i == i)
                    v.push_back(i);
                else
                {
                    v.push_back(i);
                    v.push_back(num / i);
                }
            }
        }
        return v;
    }

    bool isCoPrime(vector<int> x, vector<int> y)
    {
        int c = 0;
        for (int i = 0; i < x.size(); i++)
        {
            for (int j = 0; j < y.size(); j++)
            {
                if (x[i] == y[j])
                    c++;
                if (c > 1)
                    return false;
            }
        }
        return true;
    }

    void printFactors(vector<int> v)
    {
        for (int i : v)
            cout << i << " ";

        cout << endl;
    }
};

int main()
{
    int t;
    cin >> t;
    Solution sol;
    while (t-- > 0)
    {
        int L, R;
        cin >> L >> R;
        map<int, vector<int>> m;
        for (int i = L; i <= R; i++)
        {
            m[i] = sol.findAndPushFactors(i);
        }
        int x = 2;
        for (int x = 2; x < 2 * pow(10, 9); x++)
        {
            vector<bool> check;
            int cnt = 0;
            for (auto i : m)
            {
                vector<int> vv = sol.findAndPushFactors(x);
                if (sol.isCoPrime(vv, i.second))
                    cnt++;
            }
            if (cnt == m.size())
                break;
        }
        cout << x << endl;
        cout << endl;
    }
    return 0;
}
