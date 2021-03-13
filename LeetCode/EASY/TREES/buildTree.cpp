/*
* BUILD TREE
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
    TreeNode* buildTree(vector<int> arr, int index){
        if(arr.size() <= index || arr[index] == -1)
            return NULL;
        
        TreeNode* node = new TreeNode(arr[index]);
        node->left = buildTree(arr, 2*index + 1);
        node->right = buildTree(arr, 2*index + 2);

        return node;
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

/* TreeNode *buildTree(vector<int> nums, int ind)
{
    TreeNode *tmp = new TreeNode(nums[ind]); //10
    tmp->left = buildTree(nums, ind + 1);
    tmp->right = buildTree(nums, ind + 2);

    return tmp;
} */

void _main()
{
    vector<int> nums = {10, 5, 15, 3, 7, 18};
    nums = {4,5,7,8,2,-1,3,-1,-1,-1,-1,-1,-1,6,9};

    Solution sol;
    TreeNode* tree = sol.buildTree(nums, 0);
    printTree(tree);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}