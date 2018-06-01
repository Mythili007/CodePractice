#include<stdio.h>
int main(){
  int n;
  int a[n];
  int b[n];

  int min=0, i,j,k;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
  for(j=0;j<n;j++){
    scanf("%d",&b[j]);
  }

  for(k=0;k<a[n].size();k++){
    if(min<a[k]){
      min=a[k];
    }
    printf("Min: %d", min);
  }

}
