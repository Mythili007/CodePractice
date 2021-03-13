#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        string st[n];//, res = "";
        for(int i=0;i<n;i++){
            cin>>st[i];
        }
        string res = "";
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                res = st[i]+st[j];
                if(st[i]+st[j])                
            }

        }
    }
    return 0;
}