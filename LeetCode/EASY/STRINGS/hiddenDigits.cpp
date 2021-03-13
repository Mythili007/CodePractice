
/**
 * https://leetcode.com/problems/latest-time-by-replacing-hidden-digits/
 * 1736. Latest Time by Replacing Hidden Digits
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //ACCEPTED SOLUTION
    string maximumTime1(string time)
    {
        for (int i = 0; i < time.size(); i++)
        {
            if (i == 0)
            {
                if (time[i] == '?')
                {
                    if (time[i + 1] > '3' && time[i + 1] != '?')
                        time[i] = '1';
                    else
                        time[i] = '2';
                }
                if (time[i + 1] == '?')
                {
                    if (time[i] == '0' || time[i] == '1')
                        time[i + 1] = '9';
                    else
                        time[i + 1] = '3';
                }
            }
            else if (i > 2)
            {
                if (time[i] == '?')
                    time[i] = '5';
                if (time[i + 1] == '?')
                    time[i + 1] = '9';
            }
        }
        return time;
    }

    string maximumTime(string time)
    {
        time[0] = time[0] != '?' ? time[0] : ((time[0] == '?' || time[0] <= '3') ? '2' : '1');
        time[1] = time[1] != '?' ? time[1] : (time[0] == '2' ? '3' : '9');
        time[3] = time[3] != '?' ? time[3] : '5';
        time[4] = time[4] != '?' ? time[4] : '9';

        return time;
    }
};

void _main()
{
    Solution sol;
    string time = "2?:?0";
    time = "0?:3?";
    time = "?0:15";
    time = "??:3?";
    time = "??:?9";
    // num1 = "0", num2 = "0";
    // num1 = "6913259244", num2 = "71103343";
    string res = sol.maximumTime(time);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}