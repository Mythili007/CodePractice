#include<stdio.h>
#include<math.h>

int main(){
  float num;
  printf("Enter any num: ");
  scanf("%f", &num);
  //sqrt of any num: num pow 1/2 i.e., num pow 0.5
  float sqroot = pow(num, 0.5);
  printf("\n%f\n\n", sqroot);
}
