/**
 * https://leetcode.com/problems/destination-city/
 * 
  */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>>& paths) {
        for(int i=0;i<paths.size();i++){
            for(int j = 0;j<paths[i].size();j++){
                if(paths[i][0] == paths[i][j]){
                    cout<<"paths[i][j]: "<<paths[i][j]<<endl;
                }
            }
        }
    }
};

void _main()
{
    Solution sol;
    vector<vector<string>> paths = {{"B", "C"}, {"D", "B"}, {"C","A"}};
    string res = sol.destCity(paths);
    cout << res << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}