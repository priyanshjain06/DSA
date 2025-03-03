// class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         while (root) {
//             // If both nodes are smaller than the current node, move to the left subtree
//             if (p->val < root->val && q->val < root->val) {
//                 root = root->left;
//             }
//             // If both nodes are greater than the current node, move to the right subtree
//             else if (p->val > root->val && q->val > root->val) {
//                 root = root->right;
//             }
//             // If the current node splits p and q or matches one of them, it's the LCA
//             else {
//                 return root; //REVIEW
//             }
//         }
//         return nullptr; // Edge case: Shouldn't reach here as per problem constraints //REVIEW
//     }
// };
