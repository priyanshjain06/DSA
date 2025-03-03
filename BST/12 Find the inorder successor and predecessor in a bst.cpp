#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        while (root != NULL) {
            if (p->val >= root->val) {
                root = root->right;
            } else {
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }

    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* predecessor = NULL;
        while (root != NULL) {
            if (root->val >= p->val) {
                root = root->left;
            } else {
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};

void printInorder(TreeNode* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

int main() {
    // Example usage:
    TreeNode* root = new TreeNode(20);
    root->left = new TreeNode(10);
    root->right = new TreeNode(30);
    root->left->left = new TreeNode(5);
    root->left->right = new TreeNode(15);
    root->right->left = new TreeNode(25);
    root->right->right = new TreeNode(35);

    TreeNode* p = root->left; // Node with value 10

    Solution sol;
    TreeNode* successor = sol.inorderSuccessor(root, p);
    TreeNode* predecessor = sol.inorderPredecessor(root, p);

    if (successor != NULL) {
        cout << "Inorder Successor of " << p->val << " is " << successor->val << endl;
    } else {
        cout << "Inorder Successor of " << p->val << " does not exist." << endl;
    }

    if (predecessor != NULL) {
        cout << "Inorder Predecessor of " << p->val << " is " << predecessor->val << endl;
    } else {
        cout << "Inorder Predecessor of " << p->val << " does not exist." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
