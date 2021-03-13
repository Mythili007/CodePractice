#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int tr;
    cin >> tr;
    // truth tasks ram can perform
    int a[100] = {0};
    int b[100] = {0};
    int tR[tr];
    for (int i = 0; i < tr; i++) {
      cin >> tR[i];
      a[tR[i]] = 1;
    }
    int dr;
    cin >> dr;
    // dare tasks ram can perform
    int dR[dr];
    for (int i = 0; i < dr; i++) {
      cin >> dR[i];
      b[dR[i]] = 1;
    }

    int ts;
    cin >> ts;
    // truth task shyam can ask ram to perform
    int flag = 0;
    int tS[ts];
    for (int i = 0; i < ts; i++) {
      cin >> tS[i];
      if (a[tS[i]] == 0) {
        flag = 1;
      }
    }
    int ds;
    cin >> ds;
    // dare tasks shyam can ask ram to perform
    int dS[ds];
    for (int i = 0; i < ds; i++) {
      cin >> dS[i];
      if (b[dS[i]] == 0) {
        flag = 1;
      }
    }

    if (flag == 1) {
      cout << "no" << endl;
    } else {
      cout << "yes" << endl;
    }
  }
  return 0;
}