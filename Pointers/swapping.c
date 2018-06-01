#include<stdio.h>
int main(){
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);
  swap(&a,&b,&c);
  printf("%d %d %d", a,b,c);
  printf("\n");
  return 0;
}
swap(int *x,int *y, int *z){
  int temp;
  temp = *x;
  *x = *y;
  *y = *z;
  *z = temp;
}
