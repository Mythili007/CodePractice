#include <bits/stdc++.h>
using namespace std;

int cnt(int num)
{
    int count = 0;
    if (num == 0 || num == 6 || num == 9)
        count = 6;
    if (num == 1)
        count = 2;
    if (num == 2 || num == 3 || num == 5)
        count = 5;
    if (num == 4)
        count = 4;
    if (num == 7)
        count = 3;
    if (num == 8)
        count = 7;

    return count;
}

int totalMatches(int sum)
{
    int rem = 0, ct = 0;
    while (sum > 0)
    {
        rem = sum % 10;
        ct += cnt(rem);
        sum = sum / 10;
    }
    return ct;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, sum = 0;
        cin >> a >> b;
        sum = a + b;
        int c = totalMatches(sum);
        cout << c << endl;
    }
}