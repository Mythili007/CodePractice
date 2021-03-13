#include <bits/stdc++.h>
using namespace std;

int contSubSeq(int a[], int n) {
  int sum, sum1, count = 0;
  for (int i = 0; i < n; i++) {
    sum = a[i];
    for (int j = i + 1; j <= n; j++) {
      sum1 = a[i] + a[j];
      if (sum == sum1) {
        count++;
      }
      if (sum > sum1 || j == n) {
        break;
      }
      sum += a[j];
    }
  }
  return count;
}

int main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int count = contSubSeq(a, n);
    cout << "count: " << count << endl;
  }
  return 0;
}