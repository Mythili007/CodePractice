#include <bits/stdc++.h>
using namespace std;

void makePermutation(int a[], int n){
    map<int, int> count;
    int c =0;
    for(int i=0;i<n;i++){
        count[a[i]]++;
    }
    int nextMissing = 1;
    for(int i=0;i<n;i++){
        if(count[a[i]]!=1 || a[i]>n || a[i]<1){
            count[a[i]]--;
            c++;
        }
        while(count.find(nextMissing)!=count.end()){
            nextMissing++;
        }
        a[i] = nextMissing;
        count[nextMissing] = 1;
    }
    cout<<c;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        makePermutation(a, n);
    }
    return 0;
}