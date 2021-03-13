#include <bits/stdc++.h>
using namespace std;
const int MAX = 256;

bool canHavString2(string s1, string s2) {
  int count[MAX] = {0};

  for (int i = 0; i < s2.length(); i++) {
    count[s2[i]]++;
  }

  for (int i = 0; i < s1.length(); i++) {
    if (count[s1[i]] == 0)
      return false;
    count[s1[i]]--;
  }
  return true;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string s1, s2;
    cin >> s1 >> s2;
    int count = 0;
    if (canHavString2(s1, s2)) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}