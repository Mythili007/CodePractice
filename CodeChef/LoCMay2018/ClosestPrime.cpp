#include <bits/stdc++.h>
using namespace std;
#define maxOf(a, b) ((a) > (b) ? (a) : (b))
#define minOf(a, b) ((a) < (b) ? (a) : (b))
#define MAX 100000

vector<int> primes;
void nearestPrime() {
  int n = MAX;
  int nNew = sqrt(n);
  int m[(n / 2) + 500];
  for (int i = 1; i <= (nNew - 1) / 2; i++) {
    for (int j = (i * (i + 1)) << 1; j <= n / 2; j = j + (2 * i) + 1) {
      m[j] = 1;
    }
  }
  primes.push_back(2);
  for (int i = 1; i <= n / 2; i++) {
    if (m[i] == 0) {
      primes.push_back((2 * i) + 1);
    }
  }
}

int binarySearch(int left, int right, int n) {
  int mid = 0;
  if (left <= right) {
    mid = (left + right) / 2;
  }
  if (mid == 0 || mid == primes.size() - 1) {
    return primes[mid];
  }
  if (primes[mid] == n) {
    return primes[mid - 1];
  }
  if (primes[mid] < n && primes[mid + 1] > n) {
    return primes[mid];
  }
  if (n < primes[mid]) {
    return binarySearch(left, mid - 1, n);
  } else {
    return binarySearch(mid + 1, right, n);
  }
  return 0;
}

int _main() {
  int n, q;
  cin >> n >> q;
  int a[n], queryType, leftIndex = 0, rightIndex = 0, sum = 0, resSum = 0,
                       nearestPrimeNum, primeDiff = 0, res = 0;
  bool isQueryUsed = false;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  resSum = sum;
  for (int i = 0; i < q; i++) {
    cin >> queryType >> leftIndex >> rightIndex;
    if (isQueryUsed == false) {
      if (queryType == 2) {
        isQueryUsed = true;
        cout << sum << endl;
      }
    }
    if (queryType == 1) {
      nearestPrime();
      /* loop through array elements and get the difference of nearest prime num
       * for each num and sum it and return */
      for (int j = 0; j < n; j++) {
        nearestPrimeNum = binarySearch(0, primes.size() - 1, a[j]); // 10 - 7
        primeDiff = a[j] - nearestPrimeNum;                         // 3
        res += primeDiff;
      }
      cout << res << endl;
    }
  }
}

int main() {
  _main();
  return 0;
}
