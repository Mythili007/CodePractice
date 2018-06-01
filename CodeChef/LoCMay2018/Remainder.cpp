#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main() {
  int t = 0;
  cin >> t;
  lli n, m, rem;
  while (t-- > 0) {
    cin >> n >> m;
    rem = n%m;
    if(rem%2 == 0){
        cout << "EVEN" << endl;
    } else {
        cout << "ODD" << endl;
    }
  }
  return 0;
}