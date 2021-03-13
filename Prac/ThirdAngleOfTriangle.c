#include<stdio.h>
int main(){
  //third side of triangle
  int a1, a2;
  printf("Enter two angles: ");
  scanf("%d%d", &a1, &a2);
  int a3 = 180-(a1+a2);
  printf("Third angle of a triangle is: %d \n\n", a3);
}
