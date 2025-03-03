#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    int diameterOfBinaryTree(Node *root)
    {
        if (!root)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // Diameter passing through the current root
        int diameterThroughRoot = leftHeight + rightHeight;

        // Recursively calculate the diameter of the left and right subtrees
        int leftDiameter = diameterOfBinaryTree(root->left);
        int rightDiameter = diameterOfBinaryTree(root->right);

        // Return the maximum of all three
        return max(diameterThroughRoot, max(leftDiameter, rightDiameter));
    }

private:
    int height(Node *node)
    {
        if (!node)
        {
            return 0;
        }
        return 1 + max(height(node->left), height(node->right)); // REVIEW
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    Solution solution;

    int diameter = solution.diameterOfBinaryTree(root);

    cout << "The diameter of the binary tree is: " << diameter << endl;

    return 0;
}
