/*
 * BUILDING MIN HEAP FROM ARRAY
 */

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/**
 * Definition for a binary tree node.
 */
/* struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; */
class Solution
{
public:
    void swap(vector<int> &arr, int leftInd, int rightInd)
    {
        int temp = arr[leftInd];
        arr[leftInd] = arr[rightInd];
        arr[rightInd] = temp;
    }

    void maxHeapify(vector<int> &arr, int size, int ind)
    {
        int left = 2 * ind + 1;
        int right = 2 * ind + 2;

        int largest = ind;

        if (left < arr.size() && arr[left] > arr[largest])
            largest = left;

        if (right < arr.size() && arr[right] > arr[largest])
            largest = right;

        if (largest != ind)
        {
            swap(arr, largest, ind);
            maxHeapify(arr, size, largest);
        }
    }

    vector<int> buildMaxHeap(vector<int> &arr)
    {
        for (int i = (arr.size() - 1) / 2; i >= 0; i--)
        {
            maxHeapify(arr, arr.size(), i);
        }
        return arr;
    }
};

/* void printTree(TreeNode *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
} */

/* TreeNode *buildTree(vector<int> arr, int index)
{
    if (arr.size() <= index || arr[index] == -1)
        return NULL;

    TreeNode *node = new TreeNode(arr[index]);
    node->left = buildTree(arr, 2 * index + 1);
    node->right = buildTree(arr, 2 * index + 2);

    return node;
} */

void _main()
{
    Solution sol;
    vector<int> a = {2, 7, 4, 1, 8, 10};
    // a = {11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45};
    // TreeNode* tree = buildTree(a, 0);
    vector<int> res = sol.buildMaxHeap(a);
    for (int i : res)
        cout << i << " ";
    cout << endl;
}

int main()
{
    _main();
    return 0;
}