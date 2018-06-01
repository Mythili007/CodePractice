#include<stdio.h>
#include<limits.h>
int main(){
  int t, i;
  scanf("%d", &t);
  int first, second;
	first = second = INT_MAX;
  while(t--) {
    int t1;
    scanf("%d", &t1);
			int *n = (int *)malloc(sizeof(int *) * t1);
			for (i = 0; i <= t1 - 1; i++) {
				scanf("%d", &n[i]);
			}
// 			if (n.length > 1) {
				for (i = 0; i <= t1 - 1; i++) {
					if (n[i] < first) {
						second = first;
						first = n[i];
					} else if (n[i] < second && n[i] != first) {
						second = n[i];
					}
				}

				if (second == INT_MAX) {
					printf("-1 \n");
				} else {
					printf("%d %d\n",first, second);
				}
  }
  return 0;
  }
