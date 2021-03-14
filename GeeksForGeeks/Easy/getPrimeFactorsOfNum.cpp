/*
 * https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1 
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long int> getPrimeFactors(int num)
    {
        vector<long long int> v;
        while (num % 2 == 0)
        {
            v.push_back(2);
            num = num / 2;
        }

        for (int i = 3; i <= sqrt(num); i += 2)
        {
            while (num % i == 0)
            {
                v.push_back(i);
                num = num / i;
            }
        }

        if (num > 2)
            v.push_back(num);
        return v;
    }

    long long int largestPrimeFactor(int N)
    {
        vector<long long int> primeFactors = getPrimeFactors(N);
        sort(primeFactors.begin(), primeFactors.end());
        for (long long int i : primeFactors)
            cout << i << " ";
        cout << endl;
        return primeFactors[primeFactors.size() - 1];
    }
};

void _main()
{
    Solution sol;
    int num = 1994;
    num = 315;
    cout << sol.largestPrimeFactor(num) << endl;
    cout << endl;
}

int main()
{
    _main();
    return 0;
}