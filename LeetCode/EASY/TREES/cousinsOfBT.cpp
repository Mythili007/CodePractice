/*
* https://leetcode.com/problems/cousins-in-binary-tree/
* 993. Cousins in Binary Tree
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
    /***
     * @param map<TreeNode*, TreeNode*>
     * first - Child
     * second - Parent
     */
    map<TreeNode *, vector<int>> m;

    void traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        queue<pair<TreeNode *, int>> q;
        q.push(make_pair(root, 0));
        if (m.find(root) == m.end())
            m[root] = {0, 0};
        m[root][0] = root->val;
        m[root][1] = 0;
        while (!q.empty())
        {
            pair<TreeNode *, int> tmp = q.front();

            if (tmp.first->left)
            {
                if (m.find(tmp.first->left) == m.end())
                    m[tmp.first->left] = {0, 0};
                m[tmp.first->left][0] = tmp.first->val;
                m[tmp.first->left][1] = tmp.second + 1;
                q.push(make_pair(tmp.first->left, tmp.second + 1));
            }
            if (tmp.first->right)
            {
                if (m.find(tmp.first->right) == m.end())
                    m[tmp.first->right] = {0, 0};
                m[tmp.first->right][0] = tmp.first->val;
                m[tmp.first->right][1] = tmp.second + 1;
                q.push(make_pair(tmp.first->right, tmp.second + 1));
            }
            q.pop();
        }
    }

    void print(vector<int> vv)
    {
        for (int i : vv)
            cout << i << " ";

        cout << endl;
    }

    bool validate(int p, int q)
    {
        int p1 = 0;
        int p2 = 0;
        int d1 = 0;
        int d2 = 0;
        for (auto i : m)
        {
            // cout << "i.first: " << i.first->val << endl;
            // print(i.second);
            if (i.first->val == p)
            {
                p1 = i.second[0];
                d1 = i.second[1];
            }

            if (i.first->val == q)
            {
                p2 = i.second[0];
                d2 = i.second[1];
            }
        }

        if (p1 != p2 && d1 == d2)
            return true;
        return false;
    }

    bool isCousins(TreeNode *root, int x, int y)
    {
        if (root == NULL)
            return false;
        traverse(root);
        return validate(x, y);
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
    cout << sol.isCousins(tree, p, q) << endl;
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