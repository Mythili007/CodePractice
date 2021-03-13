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
        // string st[8];
        // string firstName[n], lastName[n];
        string *firstName = new string[n];
        string *lastName = new string[n];
        // string st[/n];
        int *a = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> firstName[i] >> lastName[i];
            a[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<"firstName[i]: "<<firstName[i]<<" firstName[j]: "<<firstName[j]<<endl;
                if (i != j)
                {
                    if (firstName[i] == firstName[j])
                    {
                        a[i] = 1;
                    }
                }
            }
            if (a[i] == 0)
            {
                cout << firstName[i] << endl;
            }
            else
            {
                cout << firstName[i] << " " << lastName[i] << endl;
            }
        }
    }
    return 0;
}