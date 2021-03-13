#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 0, n, fingersLengths[n], sheathsLengths[n], b[n], c[n], count1 = 0,
      count2 = 0;
  cin >> t;
  while (t-- > 0) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> fingersLengths[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> sheathsLengths[i];
    }
    for (int i = n - 1; i >= 0; i--) {
      c[i] = sheathsLengths[i];
    }
    for (int i = 0; i < n; i++) {
      cout << "c[i]: " << c[i] << endl;
    }
    for (int i = 0; i < n; i++) {
      if (sheathsLengths[i] > fingersLengths[i] ||
          sheathsLengths[i] == fingersLengths[i]) {
        count1 += 1;
      }
      if (c[i] > fingersLengths[i] || c[i] == fingersLengths[i]) {
        count2 += 1;
      }
    }
    cout << "count1: " << count1 << " count2: " << count2 << endl;
  }
}