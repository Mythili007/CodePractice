#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int arr[t], sum = 0, count = 0;
    for (int i = 0; i < t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sum = a + b + c;
        arr[i] = sum;
    }

    unordered_map<int, int> mp; 
    for (int i = 0; i < t; i++)  
       mp[arr[i]]++; 
  
    // Traverse through map only and 
    for (auto x : mp) 
       if (x.second == 1) {
           count++;
       }
            // cout << x.first << " "; 
    // for (int i = 0; i < t; i++)
    // {
    //     for (int j = 0; j < t; j++)
    //     {
    //         if (arr[i] != arr[j])
    //         {
    //             count++;
    //         }
    //     }
    // }
    cout << count << endl;
    return 0;
}