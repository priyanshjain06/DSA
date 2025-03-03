#include <iostream>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    // Constructor to initialize a new TreeNode
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class NodeValue//REVIEW - 
{
public:
    int maxNode, minNode, maxSize;
    // Constructor to initialize NodeValue with minNode, maxNode, and maxSize
    NodeValue(int minNode, int maxNode, int maxSize) : minNode(minNode), maxNode(maxNode), maxSize(maxSize) {}//FIXME - 
};

class Solution
{
private:
    // Helper function to find the largest BST in the binary tree
    NodeValue largestBSTSubtreeHelper(TreeNode *root)
    {
        // An empty tree is a BST of size 0.
        if (!root)
        {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }

        // Get values from left and right subtree of current tree.
        auto left = largestBSTSubtreeHelper(root->left);
        auto right = largestBSTSubtreeHelper(root->right);

        // Current node is greater than max in left AND smaller than min in right, it is a BST.
        if (left.maxNode < root->val && root->val < right.minNode)
        {
            // It is a BST.
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode),
                             left.maxSize + right.maxSize + 1);
        }

        // Otherwise, return [-inf, inf] so that parent can't be valid BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }

public:
    // Function to find the size of the largest BST in the binary tree
    int largestBSTSubtree(TreeNode *root)
    {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main()
{
    Solution sol;
    // Creating a binary tree
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);

    // Finding the size of the largest BST
    cout << "Size of the largest BST is: " << sol.largestBSTSubtree(root) << endl;

    return 0;
}
