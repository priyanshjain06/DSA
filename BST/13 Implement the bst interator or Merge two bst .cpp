#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode
{
    int val;                                                   // Value of the node
    TreeNode *left;                                            // Pointer to left child node
    TreeNode *right;                                           // Pointer to right child node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // Constructor to initialize the node
};

// This class helps us to iterate through the binary search tree (BST)
class BSTIterator
{
private:
    stack<TreeNode *> myStack; // Stack to keep track of nodes during iteration

public:
    // Constructor to initialize the iterator with the root of the BST
    BSTIterator(TreeNode *root)
    {
        pushAll(root); // We push all the left nodes starting from root into the stack
    }

    // Function to check if there is a next smallest number
    bool hasNext()
    {
        return !myStack.empty(); // If the stack is empty, there are no more nodes to visit
    }

    // Function to get the next smallest number in the BST
    int next()
    {
        // Get the node at the top of the stack
        TreeNode *tmpNode = myStack.top();
        myStack.pop(); // Pop the node since we've processed it

        // If the node has a right child, push all of its left children into the stack
        pushAll(tmpNode->right);

        // Return the value of the current node
        return tmpNode->val; // REVIEW
    }
private:
    // Helper function to push all the left nodes of a subtree into the stack
    void pushAll(TreeNode *node)
    {
        // Traverse the left side of the tree and push each node into the stack
        while (node != nullptr)
        {
            myStack.push(node);
            node = node->left; // Move to the left child
        }
    }
};

// Main function to test the BSTIterator
int main()
{
    // Creating the binary search tree
    TreeNode *root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    // Creating the BSTIterator object with the root of the tree
    BSTIterator *obj = new BSTIterator(root);

    // Iterate through the BST and print the next smallest number
    while (obj->hasNext())
    {
        cout << obj->next() << " "; // Print the next smallest number
    }

    // Clean up memory (since we are manually managing memory)
    delete obj;                // Deleting the iterator object
    delete root->right->right; // Delete right child (20)
    delete root->right->left;  // Delete left child of right subtree (9)
    delete root->right;        // Delete the right subtree (15)
    delete root->left;         // Delete left subtree (3)
    delete root;               // Finally, delete the root node

    return 0;
}
