#include<stdio.h>
int main(){
  int num,count=0,rem;
  scanf("%d", &num);
  int a = num%10;
  printf("Last Digit: %d\n", a);
  while(num>=10){
    // rem = num%10;
    num = num/10;
    count++;
  }
  printf("First Digit: %d\n", num);
  printf("Sum: %d\n\n", num+a);

}
