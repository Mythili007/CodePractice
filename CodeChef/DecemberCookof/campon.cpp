#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m;
    for (int i = 1; i <= 31; i++)
    {
        m.insert(pair<int, int>(i, i));
        cout << "m[i]: " << m[i] << endl;
    }
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int days;
        cin >> days;
        while (days-- > 0)
        {
            int d, p;
            cin>>d>>p;
            m.insert(pair<int, int>(d,p));
            map<int, int>::iterator itr;
            for(itr=m.begin();itr!=m.end();++itr){
                cout<<
            }
        }
    }
    return 0;
}