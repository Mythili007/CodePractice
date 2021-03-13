#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, b;
        cin >> n >> b;
        int width, height, price, max = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            cin >> width >> height >> price;
            if (price <= b)
            {
                if (max < (width * height))
                {
                    max = width * height;
                }
            }
        }
        if (max > 0)
        {
            cout << max << endl;
        }
        else
        {
            cout << "no tablet" << endl;
        }
    }
    return 0;
}