/*
* https://leetcode.com/problems/find-largest-value-in-each-tree-row/
* 515. Find Largest Value in Each Tree Row
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
public:
    // ACCEPTED SOLUTION - OWN
    map<int, vector<int>> m;
    
    void bfs(TreeNode *root, int lvl)
    {
        if (root == NULL)
            return;
        if (m.find(lvl) == m.end())
            m[lvl] = {};
        m[lvl].push_back(root->val);
        bfs(root->left, lvl + 1);
        bfs(root->right, lvl + 1);
    }

    void store()
    {
        for (auto i : m)
        {
            sort(i.second.begin(), i.second.end());
            v.push_back(i.second.back());
        }
    }
    
    map<int, int> mp;

    void helper(TreeNode* root, int lvl){// THIS IS PICKED FROM HIGHEST SUBMISSIONS
        if(root == NULL)
            return;
        if(mp.find(lvl) == mp.end())
            mp[lvl] = root->val;
        else {
            mp[lvl] = max(mp[lvl], root->val);
        }

        helper(root->left, lvl+1);
        helper(root->right, lvl+1);
    }

    vector<int> v;

    void storeIntoVec(){
        for(auto i: mp)
            v.push_back(i.second);
    }
    vector<int> largestValues(TreeNode *root)
    {
        if (root == NULL)
            return {};
        // bfs(root, 0);
        // store();
        helper(root, 0);
        storeIntoVec();
        return v;
    }
};

void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

TreeNode *buildTree(vector<int> arr, int index)
{
    if (arr.size() <= index || arr[index] == -1)
        return NULL;

    TreeNode *node = new TreeNode(arr[index]);
    node->left = buildTree(arr, 2 * index + 1);
    node->right = buildTree(arr, 2 * index + 2);

    return node;
}

void _main()
{
    vector<int> nums = {3, 9, 20, -101, -101, 15, 7};
    nums = {1, 2, 3, -1, 4, -1, 5};
    int p = 3;
    int q = 5;

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    vector<int> res = sol.largestValues(tree);
    for (int i : res)
        cout << i << " ";
    // printTree(tree);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}