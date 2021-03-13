#include <bits/stdc++.h>
// #include<chrono>
using namespace std;
// using namespace std::chrono;
#define MOD 10003

int amazingSubstrCount(string s, long long int len)
{
    long long int count = 0;
    vector<string> v;
    for (long long int i = 0; i<len; i++)
    {
        for (long long int j = i + 1; j <= len; j++)
        {
            // cout<<"s[i]: "<<s[i][j]<<endl;
            string st = s.substr(i, j-i);
            // cout<<"ss: "<<ss<<endl;
            // cout<<"s[j]: "<<s.substr(i,j-i)<<endl;
            if(st[0] == 'a' || st[0] == 'A' || st[0] == 'e' || st[0] == 'E' || st[0] == 'i' ||
            st[0] == 'I' || st[0] == 'O' || st[0] == 'o' || st[0] == 'U' || st[0] == 'u')
                v.push_back(st);
        }
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     // cout<<v[i]<<endl;
    //     string st = v[i];
    //     // cout << st << endl;
    //     if ()
    //     {
    //         count++;
    //     }
    // }
    // cout<<"count: "<<count<<endl;
    return v.size()%MOD;
}

int main()
{
    string str;
    cin >> str;
    long long int len = str.length();
    // auto start = high_resolution_clock::now();
    long long int count = amazingSubstrCount(str, len);
    cout<<count%MOD<<endl;
    // auto stop = high_resolution_clock::now(); 
  
    // // Get duration. Substart timepoints to  
    // // get durarion. To cast it to proper unit 
    // // use duration cast method 
    // auto duration = duration_cast<microseconds>(stop - start); 
  
    // cout << "Time taken by function: "
    //      << duration.count() << " microseconds" << endl; 
    // cout<<amazingSubstrCount(str)<<endl;
    return 0;
}