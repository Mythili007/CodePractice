/*
* https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
* 1305. All Elements in Two Binary Search Trees
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
    void populate(TreeNode *root, stack<TreeNode *> s)
    {
        if (root == NULL)
            return;
        s.push(root);
        populate(root->left, s);
    }

    vector<int> getAllElements_1(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return {};
        vector<int> v;
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;

        populate(root1, s1);
        populate(root2, s2);

        while (!s1.empty() && !s2.empty())
        {
            TreeNode *tmp1 = s1.top();
            TreeNode *tmp2 = s2.top();
            int val = 0;
            if (tmp1->val > tmp2->val)
            {
                val = tmp2->val;
                s2.pop();
                populate(root2->right, s2);
            }
            else
            {
                val = tmp1->val;
                s1.pop();
                populate(root1->right, s1);
            }
            v.push_back(val);
        }

        stack<TreeNode *> s = s1.empty() ? s2 : s1;
        while (!s.empty())
        {
            TreeNode *tmp = s.top();
            v.push_back(tmp->val);
            s.pop();
            populate(tmp->right, s);
        }
        return v;
    }
    // ================================================ //
    void inOrder(TreeNode *root, vector<int> &v)
    {
        if (root == NULL)
            return;
        inOrder(root->left, v);
        v.push_back(root->val);
        inOrder(root->right, v);
        // return v;
    }

    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        if (root1 == NULL && root2 == NULL)
            return {};
        
        vector<int> v;
        inOrder(root1, v);
        inOrder(root2, v);
        sort(v.begin(), v.end());
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
    vector<int> nums1 = {2, 1, 4};
    vector<int> nums2 = {0, 1, 3};
    // nums1 = {1, 7, 0, 7, -8, -1, -1};

    Solution sol;
    TreeNode *tree1 = buildTree(nums1, 0);
    TreeNode *tree2 = buildTree(nums2, 0);
    vector<int> res = sol.getAllElements(tree1, tree2);
    for (int j : res)
        cout << j << " ";
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