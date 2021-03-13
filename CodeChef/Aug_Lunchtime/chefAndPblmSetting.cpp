#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, m;
    cin >> n >> m;
    string st1, st2;
    int count = 0, weak = 0, x = 0, y = 0;
    for (int i = 0; i < n; i++) {
      cin >> st1 >> st2;
      if (st1 == "correct") {
        for (int j = 0; j < m; j++) {
          if (st2[j] == '1') {
            x++;
          }
        }
        if (x < m) {
          cout << "INVALID" << endl;
          count++;
          break;
        }
      } else if (st1 == "wrong") {
        for (int j = 0; j < m; j++) {
          if (st2[j] == '1') {
            y++;
          }
        }
        if (y == m) {
          cout << "WEAK" << endl;
          weak++;
          break;
        }
      }
      if (count == 0 && weak == 0) {
        cout << "FINE" << endl;
      }
    }
  }
  return 0;
}