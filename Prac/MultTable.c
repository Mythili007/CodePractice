#include<stdio.h>
int main(){
  int n,count=1;
  printf("Enter any num:");
  scanf("%d", &n);
  while(count<=10){
    printf("%d * %d = %d\n", n,count,(n*count));
    count++;
  }
  printf("\n\n");
}
