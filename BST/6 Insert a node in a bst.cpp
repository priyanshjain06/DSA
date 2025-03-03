#include <iostream>

using namespace std;

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
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == nullptr)
        {
            return new TreeNode(val); //NOTE If root is null, create a new node
        }

        TreeNode *cur = root;
        while (true)
        {
            if (cur->val < val)
            { // If val is greater than current node's value
                if (cur->right != nullptr)
                {
                    cur = cur->right; // Move to the right subtree
                }
                else
                {
                    cur->right = new TreeNode(val); // Insert new node as right child
                    break;
                }
            }
            else
            { // If val is less than or equal to current node's value
                if (cur->left != nullptr)
                {
                    cur = cur->left; // Move to the left subtree
                }
                else
                {
                    cur->left = new TreeNode(val); // Insert new node as left child
                    break;
                }
            }
        }

        return root;
    }
};

int main()
{
    // Example usage:
    // Create a sample BST
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    // Insert a new node with value 5
    Solution solution;
    TreeNode *newRoot = solution.insertIntoBST(root, 5);

    // Print the BST (optional)
    // You would need a function to print the tree structure

    return 0;
}