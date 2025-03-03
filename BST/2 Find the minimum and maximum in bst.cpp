#include <iostream>
using namespace std;
// Definition of a Binary Search Tree node
struct TreeNode
{
    int val;         // Value of the node
    TreeNode *left;  // Pointer to the left child
    TreeNode *right; // Pointer to the right child

    // Constructor to initialize a new node
    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

// Function to find the minimum value in a BST
int findMin(TreeNode *root)
{
    // If the tree is empty
    if (root == nullptr)
    {
        cout << "The tree is empty." << endl;
        return -1; // Return a special value
    }

    // Traverse to the leftmost node
    TreeNode *current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }

    // The leftmost node contains the minimum value
    return current->val;
}

// Function to find the maximum value in a BST
int findMax(TreeNode *root)
{
    // If the tree is empty
    if (root == nullptr)
    {
        cout << "The tree is empty." << endl;
        return -1; // Return a special value
    }

    // Traverse to the rightmost node
    TreeNode *current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }

    // The rightmost node contains the maximum value
    return current->val;
}

// Main function to demonstrate finding min and max
int main()
{
    // Create a simple BST
    TreeNode *root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(20);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(30);

    // Find and display the minimum value
    cout << "Minimum value in the BST: " << findMin(root) << endl;

    // Find and display the maximum value
    cout << "Maximum value in the BST: " << findMax(root) << endl;

    return 0;
}
