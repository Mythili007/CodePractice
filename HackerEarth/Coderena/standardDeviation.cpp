#include <bits/stdc++.h>
using namespace std;

int main()
{
    string st;
    int n, sum = 0, mean, a[6], diff = 0, sum1 = 0, sd = 0;

    for (int i = 0; i < 7; i++)
    {
        cin >> st;
        n = atoi(st.c_str());
        char ch[st.length() + 1];
        strcpy(ch, st.c_str());
        a[i] = n;
        sum += n;
    }
    mean = sum / 7;
    cout << "mean: " << mean << endl;
    for (int i = 0; i < 7; i++)
    {
        diff = pow(abs(a[i] - mean), 2);
        sum1 += diff;
    }
    sd = sqrt(sum1 / 7);
    cout << "sd: " << sd << endl;
    return 0;
}