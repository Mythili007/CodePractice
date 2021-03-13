#include <bits/stdc++.h>
using namespace std;

bool areParanthesisBalanced(string st)
{
    stack<char> stack;
    char ch;

    for (int i = 0; i < st.length(); i++)
    {
        if (st[i] == '(' || st[i] == '{' || st[i] == '[')
        {
            stack.push(st[i]);
            continue;
        }

        if (stack.empty())
            return false;

        switch (st[i])
        {
        case ')':
            ch = stack.top();
            stack.pop();
            if (st[i] == '{' || st[i] == '[')
                return false;

            break;

        case '}':
            ch = stack.top();
            stack.pop();
            if (st[i] == '(' || st[i] == '[')
                return false;

            break;

        case ']':
            ch = stack.top();
            stack.pop();
            if (st[i] == '{' || st[i] == '(')
                return false;

            break;
        }
    }

    return (stack.empty());
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string str;
        cin >> str;

        bool isBalanced = areParanthesisBalanced(str);
        cout << isBalanced << endl;
    }
    return 0;
}