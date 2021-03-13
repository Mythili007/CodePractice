#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    n--;
    long long int x, y;
    x = n % 26;
    x1 = n / 26;
    y = pow(2, x1);
    if (x < 2) {
      cout << y << " 0"
           << " 0" << endl;
    } else if (x < 10) {
      cout << "0 " << p << " 0" << endl;
    } else if (x < 26) {
      cout << "0 "
           << "0 " << p << endl;
    }
  }
  return 0;
}