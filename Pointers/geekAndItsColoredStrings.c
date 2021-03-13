#include <stdio.h>
int main()
{
    int t, n, r, g, b;
    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d", &n);
        scanf("%d", &r);
        scanf("%d", &g);
        scanf("%d", &b);
        int result = possibleStrings(n, r, g, b);
        printf("%d\n", result);
    }
    return 0;
}

int possibleStrings(int n, int r, int g, int b)
{
    int fact[n + 1];
    fact[0] = 1;
    int i, j, k, l;
    for (i = 1; i <= n; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    int sum = 0;
    int left = n - (r + g + b);

    for (l = 0; l <= left; l++)
    {
        for (j = 0; j <= left - l; j++)
        {
            k = left - (l + j);
            sum = sum + (fact[n] / (fact[l + r] * fact[j + b] * fact[k + g]));
        }
    }
    return sum;
}