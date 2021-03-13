#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int rows, cols;
        cin >> rows >> cols;

        int a[rows][cols];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cin >> a[i][j];
            }
        }
        int flag = 1;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if ((i == 0 && j == 0 && a[i][j] >= 2) || (i == 0 && j != cols - 1 && a[i][j] >= 3) || (i == 0 && a[i][j] >= 2))
                {
                    flag = 0;
                }
                else if ((i != rows - 1 && j == 0 && a[i][j] >= 3) || (i != rows - 1 && j != cols - 1 && a[i][j] >= 4) || (i != rows - 1 && a[i][j] >= 3))
                {
                    flag = 0;
                }
                else if ((j == 0 && a[i][j] >= 2) || (j == 0 && j != cols - 1 && a[i][j] >= 3) || (j == 0 && a[i][j] >= 2))
                {
                    flag = 0;
                }
            }
        }

        if (flag == 1)
        {
            cout << "Stable" << endl;
        }
        else
        {
            cout << "Unstable" << endl;
        }
    }
    return 0;
}