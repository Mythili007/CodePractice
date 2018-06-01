#include <stdio.h>
main()
{
    int *a, b;
    a = &b;
    *a = 7;
    printf("Value of a: %d", *a);
}