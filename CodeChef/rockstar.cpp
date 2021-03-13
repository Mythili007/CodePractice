#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string s1, s2, res1, res2 = "";
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] == 1) {
        res1 += s1[i];
    cout << "res1: " << res1 << endl;
      }
    }
  }
  return 0;
}