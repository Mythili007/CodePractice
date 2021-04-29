/* 
*https://www.codechef.com/START3C/problems/HIRETEST
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int candidates, problems, toComplete, toPartiallySolve;
        cin >> candidates >> problems >> toComplete >> toPartiallySolve;
        string arr[candidates];
        for (int i = 0; i < candidates; i++)
        {
            cin >> arr[i];
        }
        string result[candidates];
        for (int i = 0; i < candidates; i++)
        {
            string res;
            int FCount = 0, PCount = 0, UCount = 0;
            for (char ch : arr[i])
            {
                if (ch == 'F')
                    FCount++;
                else if (ch == 'U')
                    UCount++;
                else if (ch == 'P')
                    PCount++;
            }

            if (FCount >= toComplete || (FCount == toComplete - 1 && PCount >= toPartiallySolve))
                cout << "1";
            else
                cout << "0";
        }
        cout << endl;
    }
    return 0;
}