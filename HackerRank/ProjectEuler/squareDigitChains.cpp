#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define modulo 10^9+7
#define lli long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    lli n;
    cin>>n;
    lli count = 0, rem=0, sum=0, s=0, res =0;
    lli val = pow(10, n);
    if(count < val){
        while(sum!=89){
        
            while(n>0){
                rem = n%10;
                sum+=rem*rem;
                n = n/10;
            }
            n=sum;
            count++;
    res = count%modulo;
            // cout<<"count1: "<<count<<endl;
        } 
        cout<<"count2: "<<count<<endl;
    }
    
    cout<< res <<endl;
    return 0;
}
