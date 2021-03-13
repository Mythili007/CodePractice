/**
 * https://leetcode.com/problems/goal-parser-interpretation/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string interpret(string command)
    {
        string res = "";
        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'G')
                res += command[i];
            else if (command[i] == '(' && command[i + 1] == ')')
                res += 'o';
            else if (command[i] == '(' && command[i + 1] == 'a' && command[i + 2] == 'l' && command[i + 3] == ')')
                res += "al";
        }
        return res;
    }
};

void _main()
{
    Solution sol;
    string command = "G()(al)";
    command = "G()()()()(al)";
    command = "(al)G(al)()()G";
    string res = sol.interpret(command);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}