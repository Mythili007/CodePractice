#include<stdio.h>
#include<math.h>
int main(){
  //Area of equilateral triangle
  float a;
  printf("Enter side: ");
  scanf("%f", &a);
  float area = sqrt(3)/4*a*a;
  printf("Area: %f\n\n", area);
}
