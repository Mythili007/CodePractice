#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        lli n, m, k;
        cin >> n >> m >> k;
        lli a[n][m];
        for (lli i = 0; i < n; i++)
        {
            for (lli j = 0; j < m; j++)
            {
                lli num;
                cin >> num;
                a[i][j] = num;
            }
        }

        lli i, j, iOffset, jOffset, offset_cnt, sub_matrix_size, cnt = 0;
        vector<lli> res;
        for (sub_matrix_size = n; sub_matrix_size > 0; sub_matrix_size--)
        {
            offset_cnt = n - sub_matrix_size + 1;
            for (iOffset = 0; iOffset < offset_cnt; iOffset++)
            {
                for (jOffset = 0; jOffset < offset_cnt; jOffset++)
                {
                    lli sum = 0, avg = 0;

                    for (i = 0; i < sub_matrix_size; i++)
                    {
                        for (j = 0; j < sub_matrix_size; j++)
                        {
                            sum += a[i + iOffset][j + jOffset];
                            // cout << a[i + iOffset][j + jOffset] << " ";
                        }
                        cout << endl;
                    }
                    avg = sum / (sub_matrix_size * sub_matrix_size);
                    res.push_back(avg);
                    cout << endl;
                }
            }
        }
        for (lli i : res)
        {
            if (i >= k)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}