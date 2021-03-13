#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int delCost = 0, couponCost = 0;
        cin >> delCost >> couponCost;
        int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0;
        cin >> a >> b >> c;
        int firstDayMealCost = a + b + c;
        cin >> d >> e >> f;
        int secondDayMealCost = d + e + f;

        if (firstDayMealCost < 150 && secondDayMealCost < 150)
        {
            cout << "NO" << endl;
        }
        else if (firstDayMealCost >= 150 && secondDayMealCost >= 150)
        {
            int x = firstDayMealCost + secondDayMealCost + couponCost;
            int y = firstDayMealCost + secondDayMealCost + 2 * delCost;
            if (x < y)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (firstDayMealCost < 150 || secondDayMealCost < 150)
        {
            if (firstDayMealCost + delCost + secondDayMealCost + couponCost < firstDayMealCost + secondDayMealCost + 2 * delCost) //150 50
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }

        cout << endl;
    }
    return 0;
}
