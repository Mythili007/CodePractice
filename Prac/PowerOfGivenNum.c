#include<stdio.h>
int main(){
  //the form will be base and exponent
  int base, exponent, result=1;
  printf("Enter base: ");
  scanf("%d", &base);
  printf("Enter exponent: ");
  scanf("%d", &exponent);
  while(exponent != 0){
    result *= base;
    --exponent;
  }
  printf("%d\n", result);
}
