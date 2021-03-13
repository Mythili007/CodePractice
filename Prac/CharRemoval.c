#include<stdio.h>
#include<string.h>
int main(){
  char str1[15];
  char str2[15];
  char a=' ';
  int i=0, j=0;
  printf("Enter any string: ");
  scanf("%c", &str1[15]);
  printf("Enter char to be removed: \n\n");
  scanf("%c", &a);

  while (str1[i]!='\0') {
    if(str1[i]!=a){
      str2[j]=str1[i];
      j++;
    }
    i++;
  }
  str2[j]='\0';
  printf("Resultant String: %c\n\n", str2[15]);
  return 0;
}
