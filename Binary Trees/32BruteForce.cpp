                                
#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


class Solution {
public:
    // Function to perform inorder
    // traversal and count nodes
    void inorder(TreeNode* root, int &count) {
        // Base case: If the current
        // node is NULL, return
        if (root == NULL) {
            return;
        }

        // Increment count
        // for the current node
        count++;

        // Recursively call inorder
        // on the left subtree
        inorder(root->left, count);

        // Recursively call inorder
        // on the right subtree
        inorder(root->right, count);
    }

    // Function to count nodes in the binary tree
    int countNodes(TreeNode* root) {
        // Base case: If the root is NULL,
        // the tree is empty, return 0
        if (root == NULL) {
            return 0;
        }

        // Initialize count variable to
        // store the number of nodes
        int count = 0;

        // Call the inorder traversal
        // function to count nodes
        inorder(root, count);

        // Return the final count of
        // nodes in the binary tree
        return count;
    }
};




int main() {
    // Create the binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);

    Solution sol;

    // Call the countNodes function
    int totalNodes = sol.countNodes(root);

    // Print the result
    cout << "Total number of nodes in the Complete Binary Tree: "
            << totalNodes << endl;



    return 0;
}
                                
                            