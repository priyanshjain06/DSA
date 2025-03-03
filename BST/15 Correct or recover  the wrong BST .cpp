#include <iostream>
#include <climits>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
private:
    TreeNode *first;
    TreeNode *prev;
    TreeNode *middle;
    TreeNode *last;

private:
    void inorder(TreeNode *root)
    {
        if (root == NULL)
            return;

        inorder(root->left); //REVIEW - 

        if (prev != NULL && (root->val < prev->val)) //REVIEW
        {
            // If this is first violation, mark these two nodes as 'first' and 'middle'
            if (first == NULL)
            {
                first = prev;
                middle = root;
            }
            // If this is second violation, mark this node as last
            else
                last = root;
        }

        // Mark this node as previous
        prev = root; //REVIEW - 
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode *root)
    {
        first = middle = last = NULL;
        prev = new TreeNode(INT_MIN); //REVIEW
        inorder(root);
        if (first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
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
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);

    cout << "Inorder traversal of the original tree: ";
    printInorder(root);
    cout << endl;

    Solution().recoverTree(root);

    cout << "Inorder traversal of the fixed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
