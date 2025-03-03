// REVIEW - Also called as Breadth First Traversal

//  int maxDepth(Node *root)
//  {
//      if (root == NULL)
//          return 0;

//     queue<Node *> q;
//     q.push(root);
//     int depth = 0; //REVIEW

//     while (!q.empty())
//     {
//         int size = q.size();
//         depth++; //REVIEW
//         for (int i = 0; i < size; i++)
//         {
//             Node *node = q.front();
//             q.pop();
//             if (node->left)
//                 q.push(node->left);
//             if (node->right)
//                 q.push(node->right);
//         }
//     }
//     return depth;
// }
