#include <bits/stdc++.h>
using namespace std;

int findThreesInNum(int n) {
  int x, rem = 0, count = 0;
  x = n;
  while (x > 0) {
    rem = x % 10;
    if (rem == 3) {
      count++;
    }
    x = x / 10;
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, res = 0;
    cin >> n;
    n++;
    while (findThreesInNum(n) < 3) {
      n++;
    }
    cout << n << endl;
  }
}