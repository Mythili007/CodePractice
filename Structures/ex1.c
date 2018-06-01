#include <stdio.h>

struct point
{
    int a, b;
};
int main()
{
    struct point p1 = {0, 1};
    p1.a = 20;
    printf("a: %d, b: %d\n", p1.a, p1.b);
    return 0;
}