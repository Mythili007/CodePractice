#include <bits/stdc++.h>
using namespace std;
#define maxOf(a, b) ((a) > (b) ? (a) : (b))
#define minOf(a, b) ((a) < (b) ? (a) : (b))

int main() {
  int n;
  cin >> n;
  int a[n], sum = 0, b[n], k = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  for (int i = 1; i < n; i++) {
    // for (int j = i + 1; j < n; j++) {
    if (a[i - 1] != a[i]) {
      b[k] = a[i];
      k++;
      //   }
    }
  }
  for(int i = 0;i<n;i++){
      cout <<b[i]<<" ";
  }
}