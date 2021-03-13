#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  int a[n];
  int b[n];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int posn = 0, x = 1, j = 1, y = 0;
  while (x <= n) {
    for (int i = 1; i <= n; i++) {
      if (a[i] == x) {
        posn = i;
        cout << "posn: " << posn << endl;
        b[j] = posn;
        j++;
      }
    }
    x++;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (a[j] == b[i]) {
        cout << j << endl;
      }
    }
  }
  return 0;
}