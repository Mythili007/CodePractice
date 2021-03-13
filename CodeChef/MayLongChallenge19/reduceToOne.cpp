#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define pb push_back

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        long long int x = 0, y = 0;
        long long int res = 0, ans =0;
        vector<long long int> v;

        for (int i = 0; i < n; i++)
        {
            v.pb(i + 1);
        }
        int i=0;
        while (n-1 > 0)
        {
            x = v[i];
            y = v[v.size() - 1];
            res = (x + y + (x * y)) % MOD;
            v.pb(res);
            i++;
            n = n - 1;
        }
        for(int j=0;j<v.size();j++){
            cout<<"v[j]: "<<v[j]<<endl;
        }

        // ans = (v[v.size()-1])%MOD;
        // cout << ans << endl;
        cout<<v[v.size()-1]<<endl;
    }
    return 0;
}