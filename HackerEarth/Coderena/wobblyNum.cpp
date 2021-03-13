#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, k;
        cin>>n>>k;
        //find first 10 numbers and get the num at kth index
        // int a[10];
        for(int i=3;i<=1000;i++){
            if(n==i){
                cout<<i<<k<<i<<endl;
            }
        }
    }
    return 0;
}