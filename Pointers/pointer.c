#include<stdio.h>
#include "printArray.h"
int main(){
  int b[5] = {5,6,4,0,87};
  int *a = &b;
  // int i;
  // printf("sdasd -> %d\n ",*(a+0));
  // memset(&b,-1,5*sizeof(int));
  printArray(&b,5);
  return 0;
}
