#include<stdio.h>
int main(){
   int num;
   printf("Enter any number: ");
   scanf("%d",&num);
   if(num>0)
     printf("%d number is a positive number\n\n", num);
    else
    printf("%d number is a negative number\n\n", num);
}
