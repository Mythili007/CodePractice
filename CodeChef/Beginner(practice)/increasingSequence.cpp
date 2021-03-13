#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int main() {
  lli n;
  cin >> n;
  lli a[n];
  for (lli i = 0; i < n; i++) {
    cin >> a[i];
  }
//   lli temp;
//   for (lli i = 0; i < n - 1; i++) {
//     for (lli j = 1; j < n - i; j++) {
//       if (a[j - 1] > a[j]) {
//         temp = a[j - 1];
//         a[j - 1] = a[j];
//         a[j] = temp;
//       }
//     }
//   }
sort(a, a+n);
  for (lli i = 0; i < n; i++) {
    cout << a[i] << endl;
  }
  return 0;
}