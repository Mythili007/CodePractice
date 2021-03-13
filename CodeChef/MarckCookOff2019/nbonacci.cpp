#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int n, q;
    lli num, m = 1;
    vector<int> v;
    while (m--)
    {
        cin >> n >> q;

        for (int i = 0; i < n; i++)
        {
            cin >> num;
            if (i == 0)
                v.push_back(num);
            else
                v.push_back(v[i - 1] ^ num);
        }
        //f4 = f3^f2;
        v[n] = v[n - 1] ^ v[n - 2];
        while (q--)
        {
            lli k; //, sk, nextNum = 0;
            // for (int i = 0; i < q; i++)
            // {
            cin >> k;
            k = k % (n + 1);
            lli ans = 0;
            if (k == 0)
                cout << "0" << endl;
            else
            {
                //cout<<"v[k]: "<<v[k-n+1]<<endl;
                cout << v[k - 1] << endl;
            }
        }
    }
    return 0;
}