#include <vector>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

// Helper function for In-Order Traversal
void inorder(TreeNode *node, vector<int> &result)
{
    if (node == NULL)
        return;
    inorder(node->left, result);
    result.push_back(node->data);
    inorder(node->right, result);
}

// Helper function for Pre-Order Traversal
void preorder(TreeNode *node, vector<int> &result)
{
    if (node == NULL)
        return;
    result.push_back(node->data);
    preorder(node->left, result);
    preorder(node->right, result);
}

// Helper function for Post-Order Traversal
void postorder(TreeNode *node, vector<int> &result)
{
    if (node == NULL)
        return;
    postorder(node->left, result);
    postorder(node->right, result);
    result.push_back(node->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    vector<vector<int>> result(3);

    // Perform In-Order, Pre-Order, and Post-Order Traversals
    inorder(root, result[0]);
    preorder(root, result[1]);
    postorder(root, result[2]);

    return result;
}
