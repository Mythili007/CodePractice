/**
 * https://leetcode.com/problems/employee-importance/
 * 
  */

#include <bits/stdc++.h>
using namespace std;
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
class Solution
{
public:
    int getImportance(vector<Employee*> employees, int id) {
        
    }
};

void _main()
{
    Solution sol;
    string A = "this apple is sweet", B = "this apple is sour";
    vector<string> res = sol.uncommonFromSentences(A, B);
    for (string i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}