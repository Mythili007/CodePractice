#include <stdio.h>

long long gcd(long long x, long long y)
{
    if (x == y)
        return x + y;
    if (x == 0)
        return 2 * y;
    if (y == 0)
        return 2 * x;

    if (x > y)
        return gcd(x % y, y);
    if (y > x)
        return gcd(y % x, x);
}

int main()
{
    int t;
    long long x, y;
    scanf("%d", &t);
    while (t-- > 0)
    {
        scanf("%lld", &x);
        scanf("%lld", &y);
        printf("%lld\n", gcd(x, y));
    }
}