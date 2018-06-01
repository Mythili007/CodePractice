#include<stdio.h>
#include <math.h>

float findArea(int a, int b, int c){
  // if (a < 0 || b < 0 || c <0 || (a+b <= c) ||
  //       a+c <=b || b+c <=a)
  //   {
  //       printf("Not a valid trianglen");
  //       // exit(0);
  //   }
    float s = (float)(a+b+c)/2;
    // printf("s %f \n", s);
    return sqrt(s*(s-a)*(s-b)*(s-c));
}
int main(){
  //Area of triangle
  int a,b,c;
  int t, i;
  float area;
  scanf("%d", &t);
  for(i = 0;i<t;i++){
    scanf("%d%d%d", &a, &b, &c);
    printf("%.6f", findArea(a, b, c));
  }

  // int area = 0.5*base*ht;
  // printf("Area: %d\n\n", area);
}
