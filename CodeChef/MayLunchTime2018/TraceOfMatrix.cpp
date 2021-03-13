#include <bits/stdc++.h>
using namespace std;
#define maxOf(a, b) ((a) > (b) ? (a) : (b))

void _main() {
  int n;
  cin >> n;
  int a[n][n];
  int rows = 0, cols = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  int max = 0, sum = 0;
  // for cols
  for (int i = 0; i < n; i++) {
    rows = 0, cols = i, sum = 0;
    while (rows < n && cols < n) {
      sum += a[rows][cols];
      rows++;
      cols++;
    }
    max = maxOf(sum, max);
  }

  // for rows
  for (int i = 0; i < n; i++) {
    rows = i, cols = 0, sum = 0;
    while (rows < n && cols < n) {
      sum += a[rows][cols];
      rows++;
      cols++;
    }
    max = maxOf(sum, max);
  }
  cout << max << endl;
}

int main() {
  int t = 1;
  cin >> t;
  while (t-- > 0) {
    _main();
  }
  return 0;
}