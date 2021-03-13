#include <bits/stdc++.h>
using namespace std;

int findMinDiff(int a[], int n)
{
    sort(a, a + n);
    int diff = INT_MAX;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i + 1] - a[i] < diff)
        {
            diff = a[i + 1] - a[i];
        }
    }
    return diff;
}

int countDuplicates(int a[], int n){
    sort(a, a+n);
    int count =0;
    for(int i=1;i<n;i++){
        if(a[i-1]==a[i])
            count++;
    }
    return count;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n, p;
        cin >> n >> p;
        int s[n];
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s, s + n);
        for(int i=n-1;i>=0;i--){

        }
        int s1[p];
        for (int i = 0; i < p; i++)
        {
            s1[i] = s[i];
        }

        int maxElement = s1[p - 1], count = 0;
        for (int i = 0; i < p; i++)
        {
            count += maxElement - s1[i];
        }
        cout << count << endl;
    }
    return 0;
}