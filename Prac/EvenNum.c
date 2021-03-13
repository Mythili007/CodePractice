#include<stdio.h>
int main(){
  int num=1, sum=0;
  printf("Even Numbers from 1-100: ");
  while(num<=100){
    if(num%2==0){
      printf("%d ",num);
      sum+=num;
    }
    num++;
  }
  printf("Sum: %d",sum);
  printf("\n\n");
  num=1, sum=0;
  printf("Odd numbers from 1-100: ");
  while(num<=100){
    if(num%2!=0){
      printf("%d ", num);
      sum+=num;
    }
    num++;
  }
  printf("Sum: %d",sum);
  printf("\n\n");
}
