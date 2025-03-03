#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *bstFromPreorder(vector<int> &A)
    {
        int i = 0;
        return build(A, i, INT_MAX);
    }

    TreeNode *build(vector<int> &A, int &i, int bound)
    {
        if (i == A.size() || A[i] > bound)
            return NULL;
            
        TreeNode *root = new TreeNode(A[i++]); //NOTE 
        root->left = build(A, i, root->val);
        root->right = build(A, i, bound);
        return root;
    }
};

void printInorder(TreeNode *root)
{
    if (root == NULL)
        return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main()
{
    Solution solution;
    vector<int> preorder = {8, 5, 1, 7, 10, 12};
    TreeNode *root = solution.bstFromPreorder(preorder);

    cout << "Inorder traversal of constructed BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
