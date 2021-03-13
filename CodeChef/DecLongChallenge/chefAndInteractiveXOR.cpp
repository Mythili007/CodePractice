#include <bits/stdc++.h>
using namespace std;

int findMidNum(int n)
{
    int mid = (1 + n) / 2;
    return mid;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int mid = findMidNum(n);
        int xorval;
        vector<int> v;
        int count = 0;
        v.push_back(2);
        // v[mid] = mid;

        while (true)
        {

            for (int i = 1, j = 1, k = 1; i <= n; i++)
            {
                cout << "1 " << i << " " << j << " " << k << endl;
                cout << flush;
                j++;
                k++;
                count++;
                cin >> xorval;
                // v.push_back(xorval);
            }
            for (int i = 1; i <= mid; i++)
            {
                v.push_back(i);
            }
            for (int i = mid + 1; i <= n; i++)
            {
                v.push_back(i);
            }
            for (int i = 0; i < v.size(); i++)
            {
                cout << v[i] << " ";
            }
            cout << flush;
            cout << endl;
            cin >> xorval;
            if (xorval == -1)
            {
                cout << flush;
                break;
            }
            else
            {
                break;
            }
        }
    }
    cout << flush;
    return 0;
}