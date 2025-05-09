#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
    // Constructor to initialize the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    // Function to return the Right view of the binary tree
    vector<int> rightsideView(Node *root)
    {
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    }

    // Function to return the Left view of the binary tree : 
    vector<int> leftsideView(Node *root)
    {
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }

private:
    // Recursive function to traverse the binary tree and populate the left-side view
    void recursionLeft(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;

        // Add the first node encountered at this level
        if (res.size() == level)
            res.push_back(root->data);

        // Process left child first, then right child
        recursionLeft(root->left, level + 1, res); //REVIEW - 
        recursionLeft(root->right, level + 1, res);
    }

    // Recursive function to traverse the binary tree and populate the right-side view
    void recursionRight(Node *root, int level, vector<int> &res)
    {
        if (root == NULL)
            return;

        // Add the first node encountered at this level
        if (res.size() == level)
            res.push_back(root->data);

        // Process right child first, then left child
        recursionRight(root->right, level + 1, res); //REVIEW - 
        recursionRight(root->left, level + 1, res);
    }
};
int main()
{
    // Creating a sample binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    // Get the Right View traversal
    vector<int> rightView = solution.rightsideView(root);

    // Print the result for Right View
    cout << "Right View Traversal: ";
    for (auto node : rightView)
    {
        cout << node << " ";
    }
    cout << endl;

    // Get the Left View traversal
    vector<int> leftView = solution.leftsideView(root);

    // Print the result for Left View
    cout << "Left View Traversal: ";
    for (auto node : leftView)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
