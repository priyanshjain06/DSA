// NOTE
//  🌳 1st case: if left is null, print current node and go right
//  🌳 2nd case: before going left, make right most node on left subtree connected to current node, then go left
//  🌳 3rd case: if thread is already pointed to current node, then remove the thread

// REVIEW -
//  Time Complexity: O(n)
//  Space Complexity: O(1)

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// TreeNode structure
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
    // Function to perform iterative Morris
    // inorder traversal of a binary tree
    vector<int> getInorder(TreeNode *root)
    {
        // Vector to store the
        // inorder traversal result
        vector<int> inorder;
        // Pointer to the current node,
        // starting from the root
        TreeNode *cur = root; //REVIEW 

        // Loop until the current
        // node is not NULL
        while (cur != NULL) 
        {
            // If the current node's
            // left child is NULL
            if (cur->left == NULL)
            {
                // Add the value of the current
                // node to the inorder vector
                inorder.push_back(cur->val);
                // Move to the right child
                cur = cur->right;
            }
            else
            {
                // If the left child is not NULL,
                // find the predecessor (rightmost node
                // in the left subtree)
                TreeNode *prev = cur->left;
                while (prev->right && prev->right != cur)
                {
                    prev = prev->right;
                }
                // If the predecessor's right child
                // is NULL, establish a temporary link
                // and move to the left child
                if (prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else
                {
                    // If the predecessor's right child
                    // is already linked, remove the link,
                    // add current node to inorder vector,
                    // and move to the right child
                    prev->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }

        // Return the inorder
        // traversal result
        return inorder;
    }
};

int main()
{

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(6);

    Solution sol;

    vector<int> inorder = sol.getInorder(root);

    cout << "Binary Tree Morris Inorder Traversal: ";
    for (int i = 0; i < inorder.size(); i++)
    {
        cout << inorder[i] << " ";
    }
    cout << endl;

    return 0;
}
