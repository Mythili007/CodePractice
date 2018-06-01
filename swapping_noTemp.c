#include<stdio.h>
int main(){
  int a=3, b=4;
  // scanf("a: %d b: %d", &a, &b);

  a = a+b; //7
  b = a-b; //7-4 = 3
  a = a-b; //7-3 = 4
  printf("a=%d b=%d \n\n", a, b);
}
