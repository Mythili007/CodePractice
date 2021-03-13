#include <bits/stdc++.h>
using namespace std;
#define MAX 100000

void leftRotate(int a[], int n)
{
    int temp = a[0], i;
    for (i = 0; i < n-1; i++)
    {
        a[i]=a[i+1];
    }
    a[i] = temp;
    for(int j = 0;j<n;j++){
        cout<<a[j];
    }
};

// void leftRotate(int arr[], int d, int n) 
// { 
//     for (int i = 0; i < d; i++) 
//         leftRotatebyOne(arr, n); 
// } 

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        int rem = 0, x = n;
        int a[MAX], i = 0, count = 0, b[MAX], c[MAX], k = 0;
        while (n > 0)
        {
            rem = n % 10;
            a[i] = rem;
            n = n / 10;
            i++;
            count++;
        }
        for (int j = count - 1; j >= 0; j--)
        {
            b[k] = a[j];
            k++;
            // cout<<b[j]<<" ";
        }
        ostringstream st;
        st<<x;
        for(int l =0;l<count-1;l++){
            leftRotate(b,count);
        }
    }
    return 0;
}