#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n]; // = {1, 2, 3, 4, 5};
    int b[n], mul = 1;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        mul = 1;
        if (i == 0)
        {
            for (int l = i + 1; l < n; l++)
            {
                mul = mul * a[l];
            }
            b[i] = mul;
        }
        else
        {
            mul = 1;
            for (int j = i - 1; j >= 0; j--)
            {
                mul = mul * a[j];
                // cout << "j: " << j << " mult: " << mul << endl;
                b[i] = mul;
            }
            if (i < n - 1)
            {
                for (int k = i + 1; k < n; k++)
                {
                    // cout<<"k: "<< k<< " mult: "<<mul<<endl;
                    mul = mul * a[k];
                    b[i] = mul;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}