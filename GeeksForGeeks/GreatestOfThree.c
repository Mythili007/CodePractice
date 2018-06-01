#include <stdio.h>

int main() {
	//code
	int T,i,a,b,c,max;
  scanf("%d", &T);
  for(i = 0;i<T;i++){
    scanf("%d%d%d",&a,&b,&c);
  if(a>b){
    if(a>c){
      printf("%d", a);
    } else {
      printf("%d",c);
    }
  } else {
    if(b>c){
      printf("%d", b);
    } else {
      printf("%d", c);
    }
  }
}
	return 0;
}
