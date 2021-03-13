#include<bits/stdc++.h>
using namespace std;

int main(){
    /*  First, you should print a line containing a single integer X (1≤X≤3). cout
        Then, you should read a line containing a single integer Y. cin
        Finally, you should print a line containing a single integer Z (1≤Z≤3). cout */
    int x, y, z;
    x = 3;
    cout << x << endl;
    cin >> y;
    z = abs(x - y);
    cout << z << endl;
    cout << flush;
    return 0;
}