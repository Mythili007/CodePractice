#include <bits/stdc++.h>
using namespace std;

bool isCommonMultiplesPresent(int a, int b)
{
    if (a > b && (a % b == 0))
    {
        return true;
    }
    if (b > a && (b % a == 0))
    {
        return true;
    }

    //lcm present or not
    return false;
}

int lcmOf2Num(int a, int b)
{
    int max = (a > b) ? a : b;
    int lcm = 0;
    do
    {
        if (max % a == 0 && max % b == 0)
        {
            lcm = max;
            break;
        }
        else
        {
            ++max;
        }
    } while (true);
    if (lcm == 0)
        return 0;
    return 1;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, num, bL, aL, c1 = 0, c2 = 0;
        cin >> n >> bL >> aL;
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            if (num % bL == 0)
            {
                c1++;
            }
            if (num % aL == 0)
            {
                c2++;
            }
        }
        if (bL == aL && c1 >= 1 && c2 >= 1 || (c1 == 0 && c2 == 0))
        {
            cout << "BOB" << endl;
        }
        else
        {
            if (c1 == 0)
            {
                cout << "ALICE" << endl;
            }
            if (c2 == 0)
            {
                cout << "BOB" << endl;
            }
            if (c1 > 0 && c1 >= c2)
            {
                cout << "BOB" << endl;
            }
            else if (c2 > 0 && c2 > c1)
            {
                cout << "ALICE" << endl;
            }
            else if (c1 == c2 && (lcmOf2Num(aL, bL) == 1))
            {
                cout << "BOB" << endl;
            }
            else
            {
                cout << "ALICE" << endl;
            }
        }
    }
    return 0;
}