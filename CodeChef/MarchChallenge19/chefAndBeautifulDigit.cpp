#include <bits/stdc++.h>
using namespace std;
#define un_lli unsigned long long int

un_lli buildSmallestFromGivenNum(un_lli num)
{
    un_lli res = 0;
    int numFreq[10] = {0};
    while (num)
    {
        un_lli rem = num % 10;
        numFreq[rem]++;
        num = num / 10;
    }

    for (int i = 1; i <= 9; i++)
    {
        if (numFreq[i])
        {
            res = i;
            numFreq[i]--;
            break;
        }
    }
    for (int i = 0; i <= 9; i++)
    {
        while (numFreq[i]--)
        {
            res = res * 10 + i;
        }
    }
    return res;
}

int replaceDigit(un_lli num, int d1, int d2)
{
    un_lli result = 0, mul = 1, rem = 0;
    while (num % 10 > 0)
    {
        rem = num % 10;
        if (rem == d1)
            result = result + d2 * mul;
        else
            result = result + rem * mul;

        mul = mul * 10;
        num = num / 10;
    }
    // cout<<"res: "<<result<<endl;
    return result;
}

un_lli findFirstDigit(un_lli num)
{
    while (num >= 10)
    {
        num = num / 10;
    }
    return num;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        un_lli n;
        cin >> n;
        int d;
        cin >> d;
        //replace with d
        un_lli numBeforeReplacingD = buildSmallestFromGivenNum(n);
        // cout << "numBeforeReplacingD: " << numBeforeReplacingD << endl;
        un_lli firstDigit = findFirstDigit(numBeforeReplacingD), d2 = d, res = 0, lastDigit = numBeforeReplacingD % 10;
        // cout<<"d1 : "<<d1<<endl;
        // string s = reverseNum(numBeforeReplacingD);
        // cout<<"s: "<<s<<endl;
        // if (d < firstDigit)
        // {
        //     res = replaceDigit(numBeforeReplacingD, firstDigit, d2);
        // }
        if (d < lastDigit)
        {
            res = replaceDigit(numBeforeReplacingD, lastDigit, d2);
        }
        else
        {
            res = numBeforeReplacingD;
        }
        cout << res << endl;
        // un_lli a = replaceDigit();
    }
    return 0;
}