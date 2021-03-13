#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int seasons = 0;
        cin >> seasons;
        int introSongDuartion[s];
        for (int i = 0; i < seasons; i++)
            cin >> introSongDuartion[i];
        long long int sum = 0, totalDuration = 0;
        int k = 0;
        for (int i = 0; i < seasons; i++)
        {
            int episodes = 0;
            cin >> episodes;
            for (int j = 0; j < episodes; j++)
            {
                int a = 0;
                cin >> a;
                if (j == 0)
                    sum += a;
                else
                    sum += a - introSongDuartion[i];
            }
            totalDuration += sum;
        }
        cout << totalDuration << endl;
        cout << endl;
    }
    return 0;
}
