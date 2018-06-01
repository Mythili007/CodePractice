#include<stdio.h>
#include<math.h>
int main(){
  int n,k,count = 0,i,j;
  int a[n];
  scanf("%d",&n);
  for(i = 0;i<n;i++){
    scanf("%d",&a[i]);
  }
  scanf("%d",&k);
  for(i =0;i<n;i++){
    for(j = i+1;j<n;j++){
      if((a[i]+a[j])%k == 0){
        count++;
        // break;
      }

    }
  }
  printf("Count: %d\n\n", count);
}
