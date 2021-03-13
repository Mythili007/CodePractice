#include <bits/stdc++.h>
using namespace std;

int FirstFactorial(int num) {

  // code goes here
  // 4! = 4*3*2*1
  int n = num, fact = 1;
  while (n > 1) {
    fact = fact * n;
    n--;
  }
  return fact;
}

int main() {

  // keep this function call here
  int num;
  cin>>num;
  cout << FirstFactorial(num)<<endl;
  return 0;
}