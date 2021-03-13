#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a[3] = {2, 1, 0};
    sort(a, a + 4);
    int res = -1;
    for (int i = 1; i < 4; i++)
    {
        if (a[i] - a[i - 1] > 1)
        {
            res = a[i - 1] + 1;
            if (res != 0)
                break;
        }
    }
    if (res != -1)
    {
        cout << res << endl;
    } else {
        cout << a[3]+1 << endl;
    }
    return 0;
}