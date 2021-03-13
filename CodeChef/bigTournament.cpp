#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    long long int n, res = 0;
    cin >> n;
    if (n % 2 == 0) {
      res = n / 2;
    } else {
      res = (n / 2) - 1;
    }
    cout << res << endl;
  }
  return 0;
}