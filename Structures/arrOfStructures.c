#include<stdio.h>

struct point {
    int a;
};

int main(){
    struct point arr[10];
    arr[0].a = 10;
    arr[1].a = 20;
    arr[2].a = 30;

    printf("%d, %d, %d\n", arr[0].a, arr[1].a, arr[2].a);

    return 0;
}