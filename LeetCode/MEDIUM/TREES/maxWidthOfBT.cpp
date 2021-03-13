/*
* https://leetcode.com/problems/maximum-width-of-binary-tree/
* 662. Maximum Width of Binary Tree
* Given the root of a binary tree, imagine yourself standing on the right side of it, 
* return the values of the nodes you can see ordered from top to bottom.
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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<TreeNode *> q;
        map<TreeNode *, int> m;
        q.push(root);
        m[root] = 1;
        
        int currWidth = 0;
        int maxWidth = 0;

        while (!q.empty())
        {
            int size = q.size();
            int start = 0;
            int end = 0;
            for (int i = 0; i < size; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                if (i == 0)
                    start = m[tmp];

                if (i == size - 1)
                    end = m[tmp];

                if (tmp->left != NULL)
                {
                    m[tmp->left] = m[tmp] * 2;
                    q.push(tmp->left);
                }

                if (tmp->right != NULL)
                {
                    m[tmp->right] = m[tmp] * 2 + 1;
                    q.push(tmp->right);
                }
            }
            currWidth = end - start + 1;
            maxWidth = max(maxWidth, currWidth);
        }
        return maxWidth;
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
    nums1 = {1, 2, 3, -1, 5, -1, 4};

    Solution sol;
    TreeNode *tree = buildTree(nums1, 0);
    vector<int> res = sol.rightSideView(tree);
    for (int i : res)
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