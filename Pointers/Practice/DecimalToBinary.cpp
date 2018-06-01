#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, rem, i = 0, OnesCount, zerosCount;
    cin >> n;
    x = n;
    int arr[10000];
    while (x != 0)
    {
        arr[i] = x % 2;
        x = x / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        // cout << arr[j];
        if (arr[j] == 1)
        {
            OnesCount += 1;
        }
        else
        {
            zerosCount += 1;
        }
    }
    cout << OnesCount << endl;
    cout << zerosCount << endl;
    cout << endl;
    return 0;
}