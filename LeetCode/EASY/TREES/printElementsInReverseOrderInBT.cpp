/*
* PRINT BT ELEMENTS IN REVERSE ORDER USING LEVEL ORDER TRAVERSAL
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
    vector<int> elementsInReverseOrder(TreeNode *root)
    {
        if (root == NULL)
            return {};
        queue<TreeNode *> q;
        stack<TreeNode *> s;
        q.push(root);
        vector<int> v;
        while (!q.empty())
        {
            TreeNode *tmp = q.front();
            if (tmp->right)
                q.push(tmp->right);
            if (tmp->left)
                q.push(tmp->left);
            s.push(tmp);
            q.pop();
        }
        while (!s.empty())
        {
            v.push_back(s.top()->val);
            s.pop();
        }
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
    nums = {1, 2, 3, 4, 5, 6, 7};
    nums = {7, 9, 4, 9, 6, 10, 10, 6};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    vector<int> res = sol.elementsInReverseOrder(tree);
    // printTree(tree);
    for (int i : res)
        cout << i << " ";
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}