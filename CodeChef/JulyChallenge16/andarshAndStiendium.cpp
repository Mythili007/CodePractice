#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int grade[n], sum = 0, fullMarks = 0, flag = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> grade[i];
            sum += grade[i];
        }
        if (sum / n >= 4)
        {
            for (int i = 0; i < n; i++)
            {
                if (grade[i] < 3)
                {
                    flag = 1;
                }

                if (grade[i] == 5)
                {
                    fullMarks++;
                }
            }

            if (fullMarks >= 1 && flag != 1)
            {
                cout << "Yes" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}