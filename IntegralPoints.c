// Given two points p (x1, y1) and q (x2, y2), calculate the number of integral points lying on the line joining them.
//
// Input: First line of the input is the number of test cases T.
// Every test case has one input line.
// The line contains 4 inputs which are x coordinate of p, y coordinate of p, x coordinate of q and y coordinate of 1.
//
// Output:  Number of integral points between p and q


#include<stdio.h>
int main(){
  int T,i,j,k,xp,yp,xq,yq,count=0;
  scanf("%d", &T);
  for(i=0;i<T;i++){
    scanf("%d%d%d%d", &xp,&yp,&xq,&yq);
  }
  for(j=0;j<T;j++){
    for(k=xp+1;k<xq;k++){
      count++;
    }
    printf("%d",count);
  }
}
