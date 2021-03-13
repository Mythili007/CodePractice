#include <bits/stdc++.h>
using namespace std;

void solution(int A, int B)
{
    vector<int> va;
    vector<int> vb;
    vector<int> vc;

    int rem = 0;
    while (A > 0)
    {
        rem = A % 10;
        va.push_back(rem);
        A = A / 10;
    }
    rem = 0;
    while (B > 0)
    {
        rem = B % 10;
        vb.push_back(rem);
        B = B / 10;
    }
    int l =0, m = 0, n=0;
    int a[va.size()];
    int b[vb.size()];
    int c[va.size()+vb.size()];
    int j=0, k=0;
    for(int i=va.size()-1;i>=0;i--){
        a[j]=va[i];
        j++;
    }
    for(int i=vb.size()-1;i>=0;i--){
        b[k]=vb[i];
        k++;
    }
    while(l<va.size() && m<vb.size()){
        c[n++] = a[l++];
        c[n++] = b[m++];
    }   
    
    while(l<va.size()){
        c[n++]=a[l++];
    }
    while(m<vb.size()){
        c[n++]=b[m++];
    }

    for (int i = 0; i < (va.size()+vb.size()); i++)
    {
        cout << c[i];
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    solution(a, b);
    return 0;
}