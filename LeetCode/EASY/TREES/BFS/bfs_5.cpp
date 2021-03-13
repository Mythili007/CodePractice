/*
* BFS
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
    vector<vector<int>> v;
    queue<pair<TreeNode *, int>> q;
    map<int, vector<int>> m;

    void traverse(TreeNode *root)
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
    }

    void store()
    {
        for (auto i : m)
            v.push_back(i.second);
    }

    vector<vector<int>> bfs(TreeNode *root)
    {
        if (root == NULL)
            return {};

        traverse(root);
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
    nums = {1, 2, 3, -1, 5, -1, -1};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    vector<vector<int>> res = sol.bfs(tree);
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