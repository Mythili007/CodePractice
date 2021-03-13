/*
*
*/

#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

/**
 * Definition for a binary tree node.
 */
struct Node
{
    int data;           //data of the node
    Node *left, *right; //left and right references

    // Constructor of tree node
    // Node(int key)
    // {
    //     data = key;
    //     left = right = NULL;
};

Node *createNode(int val)
{
    Node *tmp = new Node;
    tmp->data = val;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

class Solution
{
public:
    map<int, pair<int, int>> m;
    void dfs(Node *root, int lvl, int hgt)
    {
        if (root == NULL)
            return;
        if (m.find(lvl) == m.end())
        {
            m[lvl] = make_pair(root->data, hgt);
        }
        else
        {
            if (m[lvl].second <= hgt)
            {
                m[lvl].second = hgt;
                m[lvl].first = root->data;
            }
        }
        dfs(root->left, lvl - 1, hgt + 1);
        dfs(root->right, lvl + 1, hgt + 1);
    }

    vector<int> v;
    void store()
    {
        for (auto i : m)
            v.push_back(i.second.first);
    }

    vector<int> bottomView(Node *root)
    {
        // Your Code Here
        if (root == NULL)
            return {};

        dfs(root, 0, 0);
        store();
        return v;
    }
};

void printTree(Node *root)
{
    if (root == NULL)
        return;
    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

Node *buildTree(vector<int> arr, int index)
{
    if (arr.size() <= index || arr[index] == -1)
        return NULL;

    Node *node = createNode(arr[index]);
    node->left = buildTree(arr, 2 * index + 1);
    node->right = buildTree(arr, 2 * index + 2);

    return node;
}

void _main()
{
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    nums = {1, 10, 39, 5};
    nums = {1,2,3,4,5,6};

    Solution sol;
    Node *tree = buildTree(nums, 0);
    // printTree(tree);
    vector<int> arr = sol.bottomView(tree);
    for (int i : arr)
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