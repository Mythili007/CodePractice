#include<stdio.h>
int main(){
  int num,count=0,rem;
  scanf("%d", &num);
  int a = num%10;
  printf("Last Digit: %d\n", a);
  while(num!=0){
    // num=num/10;
    rem = num%10;
    // printf("%d ", rem);
    num = num/10;
    count++;
  }
  printf("First Digit: %d\n", rem);
  printf("Count: %d\n", count);

}
