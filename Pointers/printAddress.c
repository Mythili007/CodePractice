#include <stdio.h>

int main()
{
    int x=10;
    // scanf("%d", &x);
    int *ptr;
    ptr = &x;
    printf("val of x: %d\n\n", *ptr);
    printf("address of x: %p",  ptr);
    return 0;
}