// #include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, x;
        cin >> n >> x;
        int p = 0;
        vector<int> v;
        char ch[n];
        v.push_back(x);
        for (int i = 0; i < n; i++)
        {
            cin >> ch[i];
            if (ch[i] == 'L')
            {
                x = x - 1;
                v.push_back(x);
            }
            if (ch[i] == 'R')
            {
                x = x + 1;
                v.push_back(x);
            }
        }
        vector<int>::iterator itr;
        std::sort(v.begin(), v.end());
        itr = std::unique(v.begin(), v.begin() + v.size());
        v.resize(std::distance(v.begin(), itr));
        cout << v.size() << endl;
    }
    return 0;
}