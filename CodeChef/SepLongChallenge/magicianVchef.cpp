#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int noOfBoxes, x, noOfSwaps, coinPresentIn, a, b, temp = 0, sum = 0;
    if (noOfSwaps < (2 * pow(10, 5))) {
      cin >> noOfBoxes >> x >> noOfSwaps;
      coinPresentIn = x;
      for (int i = 0; i < noOfSwaps; i++) {
        cin >> a >> b;
        /* either of 1 shud have x, a or b*/
        if (a != b) {
          if (x == a) {
            // swap b n x
            temp = b;
            b = x;
            x = temp;
          } else {
            // swap a and x
            temp = a;
            a = x;
            x = temp;
          }
          coinPresentIn = x;
        }
      }
      cout << coinPresentIn << endl;
      sum += noOfSwaps;
    }
  }
  return 0;
}