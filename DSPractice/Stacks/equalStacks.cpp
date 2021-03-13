#include <bits/stdc++.h>
using namespace std;
#include <stack>

int main() {
  int n1, n2, n3;
  cin >> n1 >> n2 >> n3;
  stack<int> s1;
  stack<int> s2;
  stack<int> s3;
  int data1, data2, data3, sum1 = 0, sum2 = 0, sum3 = 0, d=0;
  for (int i = 0; i < n1; i++) {
    cin >> data1;
    s1.push(data1);
    sum1 += s1.top();
  }
  for (int i = 0; i < n2; i++) {
    cin >> data2;
    s2.push(data2);
    sum2 += s2.top();
  }
  for (int i = 0; i < n3; i++) {
    cin >> data3;
    s3.push(data3);
    sum3 += s3.top();
  }
  while(!(sum1==sum2 && sum2==sum3)){
    if(sum1>sum2 || sum1>sum3){
      d = s1.pop();
      sum1-=d;
    }
    if(sum2>sum1 || sum2>sum3){
      d = s2.pop();
      sum2-=d;
    }
    if(sum3>sum1 || sum3>sum2){
      d = s3.pop();
      sum3-=d;
    }
  }
  cout << sum1 << endl;
  return 0;
}
