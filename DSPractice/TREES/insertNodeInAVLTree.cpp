#include <bits/stdc++.h>
using namespace std;
#define maxOfTwoInt(a, b) ((a) > (b) ? (a) : (b))

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    int height;
    //node creation
    // TreeNode(int x) : val(x), left(nullptr), right(nullptr), height(1) {}
};

class Solution
{
public:
    TreeNode *create(int val)
    {
        TreeNode *node = new TreeNode();
        node->val = val;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return node;
    }
    // Returns height of the node
    int height(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return node->height;
    }

    // Utility function to Left rotate
    TreeNode *leftRotate(TreeNode *node)
    {
        TreeNode *tmp = node->right;
        TreeNode *nullNode = tmp->left;

        //rotate
        tmp->left = node;
        node->right = nullNode;

        //update heights
        node->height = 1 + max(height(node->left), height(node->right));
        tmp->height = 1 + max(height(tmp->left), height(tmp->right));

        return tmp;
    }

    //Utility fintion to right rotate
    TreeNode *rightRotate(TreeNode *node)
    {
        TreeNode *tmp = node->left;
        TreeNode *nullNode = tmp->right;

        //rotate
        tmp->right = node;
        node->left = nullNode;

        //update heights
        node->height = 1 + max(height(node->left), height(node->right));
        tmp->height = 1 + max(height(tmp->left), height(tmp->right));

        return tmp;
    }

    //Get balance factor of node
    int getBalance(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        return height(node->left) - height(node->right);
    }

    //Insert node: Recursively check for balancing at every node level
    TreeNode *insertNode(TreeNode *node, int val)
    {
        //Given node is NULL, create new node with val
        if (node == NULL)
            return create(val);
        // Creating basic binary search tree
        if (val < node->val)
            node->left = insertNode(node->left, val);
        else if (val > node->val)
            node->right = insertNode(node->right, val);
        else
            return node;

        // Updating heights of the ancestor nodes
        node->height = 1 + maxOfTwoInt(height(node->left), height(node->right)); //1+max(0,1)

        // Get balanced factor of their ancestor node to check whether the tree became unbalanced at this position
        int balance = getBalance(node);

        //Check for rotation based on balanced factor
        //left left case - left->height + 1 > right->height && val < leftnode->val - right rotate
        if (balance > 1 && val < node->left->val)
            return rightRotate(node);

        //right right case - right->height + 1 > left->height && val > rightnode->val = left rotate
        if (balance < -1 && val > node->right->val)
            return leftRotate(node);

        //left right case - left->height + 1 > right->height && val > leftnode->val
        if (balance > 1 && val > node->left->val)
        {
            //left rotate to insert the value
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        //right left case - right->height+1 > left->height && val < rightnode->val
        if (balance < -1 && val < node->right->val)
        {
            //right rotate to insert val
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }
        return node;
    }
};

void preOrder(TreeNode *node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    preOrder(node->left);
    preOrder(node->right);
}

void inOrder(TreeNode *node)
{
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->val << " ";
    inOrder(node->right);
}

void _main()
{
    Solution sol;
    TreeNode *root = NULL;
    root = sol.insertNode(root, 10);
    root = sol.insertNode(root, 20);
    root = sol.insertNode(root, 30);
    root = sol.insertNode(root, 40);
    root = sol.insertNode(root, 50);
    root = sol.insertNode(root, 25);

    //print preorder
    preOrder(root);

    //print inorder
    // inOrder(root);
}

int main()
{

    int t = 1;
    // cin >> t;
    while (t--)
        _main();

    return 0;
}