#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


int main() {
    int n;
    scanf("%d", &n);
    int p;
    scanf("%d", &p);
    int min = 0;
    min = n/2-p/2;
    if(min>p/2){
        min = p/2;
    }
    printf("%d", min);
    return 0;
}
