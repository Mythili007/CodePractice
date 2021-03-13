#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (a == 0)
        return b;

    return gcd(b % a, a);
}

int findGcd(int n, int a[])
{
    int ans = a[0];
    for (int i = 1; i < n; i++)
    {
        ans = gcd(a[i], ans);
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << gcd(n, a) << endl;
    return 0;
}