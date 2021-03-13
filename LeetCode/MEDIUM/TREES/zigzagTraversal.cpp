/*
* https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
* 103. Binary Tree Zigzag Level Order Traversal
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
    queue<TreeNode *> q;
    vector<vector<int>> res;

    void bfs(TreeNode *root)
    {
        if (root == NULL)
            return;
        q.push(root);
        bool lToR = true;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                int ind = lToR ? i : size - 1 - i;//Decide the index to fill whether from first or last
                q.pop();
                v[ind] = tmp->val;
                if (tmp->left)
                    q.push(tmp->left);
                if (tmp->right)
                    q.push(tmp->right);
            }
            lToR = !lToR;
            res.push_back(v);
        }
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        bfs(root);
        return res;
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
    nums = {3, 9, 20, -1, -1, 15, 7};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    vector<vector<int>> final = sol.zigzagLevelOrder(tree);
    for (vector<int> i : final)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}