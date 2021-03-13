// #include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

int convertBinToDecimal(int n)
{
    int base = 1;
    int temp = n;
    int decVal = 0;

    while (temp)
    {
        int rem = temp % 10;
        temp = temp / 10;
        decVal += rem * base;
        base = base * 2;
    }
    return decVal;
}

int decToBinary(int n)
{
    int binArr[32];
    int i = 0, c = 0;

    while (n)
    {
        binArr[i] = n % 2;
        n = n / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--)
    {
        if (binArr[j] == 1)
            c++;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string st[n];
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> st[i];
            int x = stoi(st[i]);
            res ^= convertBinToDecimal(x);
        }
        cout << decToBinary(res) << endl;
    }
    return 0;
}