#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    bool reverse; // true -> reverse inorder (right-to-left), false -> inorder (left-to-right)

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    /** @return whether we have a next smallest/largest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

    /** @return the next smallest/largest number */
    int next()
    {
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if (reverse)
        {
            pushAll(tmpNode->left); // For reverse inorder, go left
        }
        else
        {
            pushAll(tmpNode->right); // For normal inorder, go right
        }
        return tmpNode->val;
    }

private:
    void pushAll(TreeNode *node)
    {
        while (node)
        {
            myStack.push(node);
            if (reverse)
            {
                node = node->right; // Reverse inorder
            }
            else
            {
                node = node->left; // Normal inorder
            }
        }
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (!root)
            return false;

        // Create two iterators: one for the smallest and one for the largest values
        BSTIterator l(root, false); // Inorder iterator (left-to-right)
        BSTIterator r(root, true);  // Reverse inorder iterator (right-to-left)

        int i = l.next(); // Smallest value
        int j = r.next(); // Largest value

        // Two-pointer approach
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next(); // Move the left iterator forward
            else
                j = r.next(); // Move the right iterator backward
        }
        return false; // If no such pair is found //REVIEW - 
    }
};
