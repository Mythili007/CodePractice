#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int totalIncome, tax = 0;
        cin >> totalIncome;
        if (totalIncome > 250000 && totalIncome < 500000)
        {
            tax = (500000 - 250000) * 0.05;
        }
        if (totalIncome > 500000 && totalIncome < 750000)
        {
            tax += (750000 - 500000) * 0.10;
        }
        if (totalIncome > 750000 && totalIncome < 1000000)
        {
            tax += (1000000 - 750000) * 0.15;
        }
        if (totalIncome > 1000000 && totalIncome < 1250000)
        {
            tax += (1250000 - 1000000) * 0.20;
        }
        if (totalIncome > 1250000 || totalIncome < 1500000)
        {
            tax += (1500000 - 1250000) * 0.25;
        }
        if(totalIncome>1500000){
            tax+=
        }
    }
    return 0;
}