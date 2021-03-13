#include <bits/stdc++.h>
using namespace std;
#define li long int

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, x, count = 0;
    cin >> n >> x;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (a[i] >= x) {
        count++;
      }
    }
    if (count >= 1) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
