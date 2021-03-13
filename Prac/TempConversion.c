#include<stdio.h>
int main(){
  float temp;
  printf("Enter temperature:");
  scanf("%f", &temp);
  float celToFa = (temp*1.8)+32;
  float FaToCel = (temp-32)/1.8;
  printf("Temp in cel: %f", celToFa);
  printf("Temp in Fa: %f", FaToCel);
}
