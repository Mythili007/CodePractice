#include <bits/stdc++.h>
using namespace std;
#define minOf(a, b) ((a) > (b) ? (b) : (a))

int nearestPowerOfTwo(int n) {
  int res = 0;
  for (int i = n; i >= 1; i--) {
    if (((i) & (i - 1)) == 0) {
      res = i;
      break;
    }
  }
  return res;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int diff, count;
    diff = n;
    if (n == nearestPowerOfTwo(n)) {
      count = 1;
    } else {
      for (int i = 0; i < 2; i++) {
        diff = diff - nearestPowerOfTwo(diff); // 6
      }
      count = diff;
    }
    cout << count << endl;
  }
  return 0;
}
