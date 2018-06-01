#include<stdio.h>
int main(){
   float m1,m2,m3,m4,m5;
   printf("Enter 5 subjects marks: ");
   scanf("%f%f%f%f%f", &m1,&m2,&m3,&m4,&m5);

   float tot=m1+m2+m3+m4+m5;
   float avg=tot/5;
   float per=(tot/500)*100;

   printf("Total Marks: %.2f\n Average: %.2f\n Percentage: %.2f\n", tot,avg,per);
}
