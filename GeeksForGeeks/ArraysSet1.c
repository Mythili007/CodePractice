#include<stdio.h>
int main(){
  int t, i, j;
  scanf("%d", &t);
  for(i = 0;i<t;i++){
    int size;
    scanf("%d", &size);
    int ar[size];
    int sum = 0;
    float avg;
    for(j=0;j<size;j++){
      scanf("%d", &ar[j]);
      sum = sum+ar[j];
    }
    printf("%d ",sum);
    avg = (float) sum/size;
    printf("%lf",avg);

  }
}
