#include<stdio.h>
int main(){
  int n,num=1,sum=0;
  scanf("%d", &n);
  while(num<=n){
      sum+=num;
      num++;
  }
  printf("%d ",sum);

  printf("\n\n");
  num=n;
  while(num){
      printf("%d ",num);
      num--;
  }
  printf("\n\n");

}
