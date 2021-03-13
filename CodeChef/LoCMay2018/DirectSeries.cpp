#include <bits/stdc++.h>
using namespace std;
// #define MOD 1000000007

int main() {
  int t = 0;
  cin >> t;
  while (t-- > 0) {
    unsigned int M = 1000000007;
    long long int n1, i, sum = 0, prod = 1, k, n2;
    // int n2;
    cin >> n1 >> n2;
    sum = (2*((2*n1*n1)+1))%M;
    // for (i = 1; i <= n1; i++) {
    //   prod = 1;
    //   for (k = 1; k <= n2; k++) {
    //     prod = prod * (i + k);
    //   }
    //   sum = (sum + prod)%M;
    //   //   cout << "sum: " << sum << endl;
    // }
    cout << sum << endl;
  }
  return 0;
}