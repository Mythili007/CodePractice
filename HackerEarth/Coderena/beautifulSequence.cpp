#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> t;
    while (t-- > 0)
    {
        cin >> n;
        int a[n], count = 0, temp = 0, count1 = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i=n-2;i>=0;i--){
            if(a[i-1]>a[i])
                count++;
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i - 1] > a[i])
            {
                count++;
            }
        }
        if (count == 1 && a[0] > a[1])
        {
            count = 1;
        }
        else
        {
            for (int i = 1; i < n; i++)
            {
                if (a[i - 1] == a[i])
                {
                    count1++;
                }
                if (a[i - 1] > a[i])
                {
                    temp = a[i - 1];
                    a[i - 1] = a[i];
                    a[i] = temp;

                    count++;
                }
            }
            if (count1 == n-1)
            {
                count = n - 1;
            }
        }
        // if (count == n - 1)
        // {
        //     count = 1;
        // }
        cout << count << endl;
    }

    return 0;
}