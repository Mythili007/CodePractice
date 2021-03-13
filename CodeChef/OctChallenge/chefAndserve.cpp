#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int p1, p2, k;
    cin >> p1 >> p2 >> k;
    int servesDone = 0;
    servesDone = (p1 + p2) / k;
    if (servesDone % 2 == 0) {
      cout << "CHEF" << endl;
    } else {
      cout << "COOK" << endl;
    }
  }
  return 0;
}