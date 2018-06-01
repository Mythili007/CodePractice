#include<stdio.h>
int main(){
  //swapping 2 num using temp variable
  int a,b,temp;
  scanf("%d%d", &a, &b);

  temp = a;
  a = b;
  b = temp;
  printf("a = %d and b = %d\n\n", a, b);
}
