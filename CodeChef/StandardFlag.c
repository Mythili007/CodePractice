#include <stdio.h>

int main()
{
    int n, m, invalid = 1, flag = -1, i = 0, j = 0;
    scanf("%d %d", &n, &m);
    char a[n][m];
    for (i = 0; i < n; i++)
    {
        scanf("%s", a[i]);
        for (j = 0; j < m; j++)
        {
            if (j != 0 && a[i][j - 1] != a[i][j])
            {
                invalid = 1;
                break;
            }
        }
        if (a[i][0] == flag)
        {
            invalid = 1;
            break;
        }
        flag = a[i][0];
    }
    if (invalid == 1)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
    }
    return 0;
}
