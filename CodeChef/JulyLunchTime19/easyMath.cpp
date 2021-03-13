#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int num)
{
    int rem = 0, sum = 0;

    while (num > 0)
    {
        rem = num % 10;
        sum += rem;
        num = num / 10;
    }
    return sum;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int max = INT_MIN, prod = 1, sum=0;
        ;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                prod = a[i] * a[j];
                sum = sumOfDigits(prod);
                if (sum > max)
                {
                    max = sum;
                }
            }
        }

        cout << max << endl;
    }
    return 0;
}
