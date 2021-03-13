#include <bits/stdc++.h>
using namespace std;

void atmMachine(long int a[], long int n, long int k) {
  for (int i = 0; i < n; i++) {
    if (k >= 0) {
      if (a[i] <= k) {
        k = k - a[i];
        cout << "1";
      } else {
        cout << "0";
      }
    }
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    long int n, k;
    cin >> n >> k;
    long int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    atmMachine(a, n, k);
  }
  return 0;
}