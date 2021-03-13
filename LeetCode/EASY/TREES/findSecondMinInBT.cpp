/*
* https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
* 671. Second Minimum Node In a Binary Tree
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
    // # ACCEPTED BRUTE FORCE SOLUTION
    vector<int> v;
    void inOrder(TreeNode *root)
    {
        if (root == NULL)
            return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }

    int secondMin()
    {
        sort(v.begin(), v.end());
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i] > v[i-1])
                return v[i];
        }
        return -1;
    }
    int findSecondMinimumValue_1(TreeNode *root)
    {
        if (root == NULL)
            return -1;
        inOrder(root);
        return secondMin();
    }


    //# ANOTHER SOLUTION - OPTIMIZED
    int secondMin(TreeNode* root, int val){
        if(root == NULL)
            return -1;
        if(root->val != val)
            return root->val;
        
        int left = secondMin(root->left, val);
        int right = secondMin(root->right, val);

        if(left == -1)
            return right;
        if(right == -1)
            return left;
        
        return min(left, right);
    }

    int findSecondMinimumValue(TreeNode *root)
    {
        if (root == NULL)
            return -1;

        return secondMin(root, root->val);
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
    vector<int> nums = {3, 5, 1, 6, 2, 9, 8, -1, -1, 7, 4};
    nums = {1, 2, 2, 3, 4, 4, 3};
    nums = {1, 2, 2, -1, 3, -1, 3};
    nums = {2,2,5,-1,-1,5,7};
    Solution sol;
    TreeNode *tree = buildTree(nums, 0);

    int res = sol.findSecondMinimumValue(tree);
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