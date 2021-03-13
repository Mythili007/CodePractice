#include <bits/stdc++.h>
using namespace std;
#define max(a, b) (a > b) ? (a) : (b)
#define lli long long int

int main()
{
    long int n;
    cin >> n;
    lli a[n];
    for (lli i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    lli res = 0;
    bool allSame = true;
    long int i = 1;
    while (i < n)
    {
        if (a[i] != a[i - 1])
        {
            allSame = false;
            break;
        }
        i++;
    }

    if (allSame)
        cout << "0" << endl;
    else
    {
        lli maxElement = *std::max_element(a, a + n);
        lli secMax = 0;

        for (lli j = 0; j < n; j++)
        {
            if (a[j] < maxElement && a[j] > secMax)
                secMax = a[j];
        }
        cout << secMax << endl;
    }

    return 0;
}