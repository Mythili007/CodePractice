#include <bits/stdc++.h>
using namespace std;



bool isNumberContainsAllDigits(int n, int d){
    int rem1 =0, rem2 =0;
    vector<int> v1;
    vector<int> v2;

    while(n>0){
        rem1 = n%10;
        v1.push_back(rem1);
        n=n/10;
    }

     while( d>0){
        rem2 = d%10;
        v2.push_back(rem2);
        d=d/10;
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    if(v1 == v2){
        return true;
    } else {
        return false;
    }
}

void multiplesOfN(int n, int p, int q, int allowedVal){
    int count=0, count1=0;
    for(int i=p;i<=q;i++){
        if(i%n==0){
            count++;
            
            if(isNumberContainsAllDigits(i, allowedVal))
                count1++;
        }
    }
    cout<<count1<<endl;
}



int main(){
    int n, p,q;
    cin>>n>>p>>q;
    int d;
    cin>>d;
    multiplesOfN(n, p,q, d);

    return 0;
}