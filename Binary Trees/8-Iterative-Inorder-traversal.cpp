#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Define the TreeNode structure
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to perform inorder traversal
    // of a binary tree iteratively
    vector<int> inorderTraversal(TreeNode *root)
    {
        // Initialize vector to store
        // the inorder traversal result
        vector<int> inorder; //REVIEW 

        // If the root is null, return
        // an empty traversal result
        if (root == nullptr)
        {
            return inorder;
        }

        // Create a stack to store nodes
        stack<TreeNode *> st;
        TreeNode *current = root; // REVIEW

        // Perform iterative inorder traversal
        while (current != nullptr || !st.empty()) //REVIEW 
        {
            // Reach the leftmost node of the current node
            while (current != nullptr) //REVIEW 
            {
                st.push(current);
                current = current->left;
            }

            // Current must be null at this point
            current = st.top();
            st.pop();

            // Add the node's value to the inorder traversal result
            inorder.push_back(current->val);

            // Move to the right subtree
            current = current->right;
        }

        // Return the inorder traversal result
        return inorder;
    }
};

int main()
{
    // Creating a binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Initializing the Solution class
    Solution sol;

    // Getting the inorder traversal
    vector<int> result = sol.inorderTraversal(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
