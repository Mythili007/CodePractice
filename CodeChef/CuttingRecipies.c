#include <stdio.h>
int gcdOfTwoNum(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        gcdOfTwoNum(b, a % b);
    }
}
int main()
{
    int t, n, a[n], i, j, k, num;
    // printf("%d", 3%2);
    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[j]);
        }
        num = a[0];
        for (i = 1; i < n; i++)
        {
            num = gcdOfTwoNum(num, a[i]);
        }
        for (k = 0; k < n; k++)
        {
            printf("%d ", a[k] / num);
        }
    }
    return 0;
}
