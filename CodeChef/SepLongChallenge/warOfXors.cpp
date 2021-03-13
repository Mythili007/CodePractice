#include <bits/stdc++.h>
using namespace std;

int xorOf2Num(int a, int b) { return (a ^ b); }
void primeFactorsOfaNum(int n) {
  while (n % 2 == 0) {
    printf("%d ", 2);
    n = n / 2;
  }
  for (int i = 3; i <= sqrt(n); i = i + 2) {
    while (n % i == 0) {
      printf("%d ", i);
      n = n / i;
    }
  }
  if (n > 2)
    printf("%d ", n);
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int xorVal = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        xorVal = xorOf2Num(a[i], a[j]);
        cout << "a[i]: " << a[i] << " a[j]: " << a[j] << endl;
        cout << "xor of 2 num: " << xorOf2Num(a[i], a[j]) << endl;
        primeFactorsOfaNum(xorVal);
        break;
      }
      break;
    }
  }
  return 0;
}