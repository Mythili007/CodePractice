#include<stdio.h>
#include<math.h>
int main(){
  //1 meter = 100 cm
  //1 km = 1000 m
  //1 km = 100000 cm
  int len=0;
  printf("Enter length: ");
  scanf("%d", &len);
  int mtr = len * 0.02;
  int km = len * pow(10, -5);
  printf("In meters: %d\n", mtr);
  printf("In Kilo meters: %d\n", km);
}
