/**
 * https://leetcode.com/explore/challenge/card/march-leetcoding-challenge-2021/589/week-2-march-8th-march-14th/3667/
 * Integer to Roman
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string intToRoman(int num) {
        map<int, string> m;
        m[1] = "I";
        m[5] = "V";
        m[10] = "X";
        m[50] = "L";
        m[100] = "C";
        m[500] = "D";
        m[1000] = "M";

        m[4] = "IV";
        m[9] = "IX";
        m[40] = "XL";
        m[90] = "XC";
        m[400] = "CD";
        m[900] = "CM";

        while(num > 0){
            int r = num%10;
            r*pow(10, 0);
        }
    }
};

void _main()
{
    Solution sol;
    vector<int> a = {1, 2, 3, 9};
    int k = 34;

    vector<int> res = sol.addToArrayForm(a, k);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}