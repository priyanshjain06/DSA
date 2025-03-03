// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     TreeNode* insertIntoBST(TreeNode* root, int val) {
//         // If the tree is empty, create a new node with the value
//         if (!root) {
//             return new TreeNode(val);
//         }

//         // Traverse the tree to find the correct insertion point
//         if (val < root->val) {
//             // If the value is smaller, go to the left subtree
//             root->left = insertIntoBST(root->left, val);
//         } else {
//             // If the value is larger, go to the right subtree
//             root->right = insertIntoBST(root->right, val);
//         }
//         // Return the unchanged root
//         return root;
//     }
// };
