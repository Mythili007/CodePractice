/*
* https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
* 1161. Maximum Level Sum of a Binary Tree
* Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
* Return the smallest level x such that the sum of all the values of nodes at level x is maximal.
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
    int sum = INT_MIN;
    int lvl = 0;

    void bfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        q.push(make_pair(root, 1));
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
    }

    int vectorSum(vector<int> &v)
    {
        int s = 0;
        for (int i : v)
            s += i;
        return s;
    }

    void findMaxLevelSum()
    {
        for (auto i : m)
        {
            int val = vectorSum(i.second);
            if (val > sum)
            {
                sum = val;
                lvl = i.first;
            }
        }
    }

    int maxLevelSum(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        bfs(root);
        findMaxLevelSum();
        return lvl;
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
    nums1 = {1, 7, 0, 7, -8, -1, -1};

    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    int res = sol.maxLevelSum(tree);
    cout << res << endl;
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