/*
* https://leetcode.com/problems/diameter-of-binary-tree/
* 543. Diameter of Binary Tree
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
    map<TreeNode *, vector<int>> m;
    void distance(TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            m[root] = {0, 0, 0};
            return;
        }

        distance(root->left);
        distance(root->right);

        m[root] = {0, 0, 0};
        if (root->left)
            m[root][0] = 1 + max(m[root->left][0], m[root->left][1]);
            cout<<"root_left: " << m[root][0]<< "  at root val: "<< root->val <<endl;
            cout<<"left_0: " <<m[root->left][0]<< "  left_1: " << m[root->left][1]<<endl;
            cout<<endl;

        if (root->right){
            m[root][1] = 1 + max(m[root->right][0], m[root->right][1]);
            cout<<"root_right: " << m[root][1]<< "  at root val: "<< root->val<<endl;
            cout<<"right_0: " <<m[root->right][0]<< "  right_1: " << m[root->right][1]<<endl;
            cout<<endl;
        }

        m[root][2] = m[root][0] + m[root][1];
        cout<<endl;
        cout<<"root_2: before  "<<m[root][2]<<endl;
        /* if (m[root][0] != 0 && m[root][1] != 0)
            m[root][2] = m[root][2] - 1; */
        
        cout<<"root_2: after  "<<m[root][2]<<endl;
    }
    vector<int> v;
    int getLongestPath(){
        int maxx = INT_MIN;
        for(auto i:m){
            v.push_back(i.second[2]);
        }
        for(int i: v)
            maxx = max(maxx, i);
        
        return maxx;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        distance(root);
        return getLongestPath();
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
    nums = {1, 2, 3,4,5};

    Solution sol;
    TreeNode *tree = buildTree(nums, 0);
    cout << sol.diameterOfBinaryTree(tree) << endl;
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