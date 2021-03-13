#include<bits/stdc++.h>
using namespace std;

string convertToBinary(int n){
    string res;
    for(int i=31;i>=0;i--){
        int a = n>>i;
        if(a&1) res+="1";
        else res+="0";
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    string s = convertToBinary(n);
    cout<<s<<endl;
    return 0;
}

