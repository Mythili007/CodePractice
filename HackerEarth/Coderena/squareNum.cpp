#include<bits/stdc++.h>
using namespace std;

bool squareNum(int x){
    long double sqrt_val = sqrt(x);
    cout<<"sqrt val: "<<sqrt_val << endl;
    cout<<"floor of sqrt val: "<<floor(sqrt_val)<<endl;
    return ((sqrt_val - floor(sqrt_val))==0);
}

int main(){
    int n;
    cin>>n;
    if(squareNum(n))
        cout << "YES" << endl;
    else 
        cout << "NO" <<endl;
    return 0;
}