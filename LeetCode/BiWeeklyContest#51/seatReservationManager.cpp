#include <bits/stdc++.h>
using namespace std;

class SeatManager
{
    set<int> ss;

public:
    SeatManager(int n)
    {
        for (int i = 1; i <= n; i++)
            ss.insert(i);
    }

    int reserve()
    {
        int el = *begin(ss);
        ss.erase(begin(ss));
        return el;
    }

    void unreserve(int seatNumber)
    {
        ss.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */

void _main()
{
    SeatManager seatManager;
    vector<vector<int>> vec = {{5}, {}, {}, {2}, {}, {}, {}, {}, {5}};
    int i = 0;
    for (vector<int> v : vec)
    {
        if (i == 0)
            SeatManager(v[0]);
        else if (i > 0 && v.size() == 0)
        {
            int res = seatManager.reserve();
            cout << "reserved: " << res << endl;
        }
        else
            seatManager.unreserve(v[0]);
    }
    cout << endl;
}

int main()
{
    _main();
    return 0;
}