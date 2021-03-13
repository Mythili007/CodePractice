/*
* https://leetcode.com/problems/average-of-levels-in-binary-tree/
* 637. Average of Levels in Binary Tree
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
    queue<pair<TreeNode *, int>> q;
    map<int, vector<int>> m;
    vector<double> v;

    void findAverage(TreeNode *root)
    {
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<TreeNode *, int> tmp = q.front();
            if (m.find(tmp.second) == m.end())
                m[tmp.second] = {};

            m[tmp.second].push_back(tmp.first->val);
            if (tmp.first->left)
                q.push(make_pair(tmp.first->left, tmp.second + 1));

            if (tmp.first->right)
                q.push(make_pair(tmp.first->right, tmp.second + 1));

            q.pop();
        }
        for (auto i : m)
        {
            double val = accumulate(i.second.begin(), i.second.end(), 0.0) / i.second.size();
            v.push_back(val);
        }
    }

    vector<double> averageOfLevels(TreeNode *root)
    {
        if (root == NULL)
            return {};
        findAverage(root);
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
    vector<int> nums1 = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    nums1 = {3, 9, 20, -1, -1, 15, 7};

    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    vector<double> res = sol.averageOfLevels(tree);
    for (double i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}