// TreeNode *deleteNode(TreeNode *root, int key)
// {
//     if (root == NULL)
//     {
//         return NULL;
//     }
//     if (root->val == key)
//     {
//         return helper(root);
//     }
//     TreeNode *dummy = root; //NOTE
//     while (root != NULL)
//     {
//         if (root->val > key)
//         {
//             if (root->left != NULL && root->left->val == key) //REVIEW -
//             {
//                 root->left = helper(root->left);
//                 break;//REVIEW -
//             }
//             else
//             {
//                 root = root->left;
//             }
//         }
//         else
//         {
//             if (root->right != NULL && root->right->val == key)
//             {
//                 root->right = helper(root->right);
//                 break;
//             }
//             else
//             {
//                 root = root->right;
//             }
//         }
//     }
//     return dummy; //REVIEW
// }

// TreeNode *helper(TreeNode *root)
// {
//     if (root->left == NULL)
//     {
//         return root->right;
//     }
//     else if (root->right == NULL)
//     {
//         return root->left;
//     }

//     TreeNode *rightChild = root->right;
//     TreeNode *lastRight = findLastRight(root->left);
//     lastRight->right = rightChild;
//     return root->left; //REVIEW -
// }

// TreeNode *findLastRight(TreeNode *root)//REVIEW -
// {
//     if (root->right == NULL)
//     {
//         return root;
//     }
//     return findLastRight(root->right);
// }
