/*
* LEVEL ORDER TRAVERSAL USING BFS
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
    map<int, vector<int>> m;
    vector<vector<int>> v;
    queue<pair<TreeNode *, int>> q;

    void bfs(TreeNode *root)
    {
        if (root == NULL)
            return;

        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            pair<TreeNode *, int> p = q.front();
            if (m.find(p.second) == m.end())
                m[p.second] = {};
            m[p.second].push_back(p.first->val);
            if (p.first->left)
                q.push(make_pair(p.first->left, p.second + 1));

            if (p.first->right)
                q.push(make_pair(p.first->right, p.second + 1));

            q.pop();
        }
    }

    void store()
    {
        for (auto i : m)
            v.push_back(i.second);
    }

    vector<vector<int>> levelOrderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        bfs(root);
        store();
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
    nums = {1, 3, 4, 0, 5, -1, 7, -1, -1, -1, -1, -1, -1, 8, 9};
    // nums = {1, 2, 3, -1, 5, -1, -1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<vector<int>> res = sol.levelOrderTraversal(tree);
    for (vector<int> i : res)
    {
        for (int j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
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