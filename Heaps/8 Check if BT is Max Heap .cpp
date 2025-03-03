#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Count the total number of nodes in the binary tree
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Check if the tree is a Complete Binary Tree (CBT)
bool isCBT(Node *root, int index, int cnt)
{
    if (root == NULL)
        return true;

    if (index >= cnt)
        return false;

    return isCBT(root->left, 2 * index + 1, cnt) && isCBT(root->right, 2 * index + 2, cnt);
}


// Check Max-Heap property
bool isMaxOrder(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
        return root->data > root->left->data;

    return (root->data > root->left->data) &&
           (root->data > root->right->data) &&
           isMaxOrder(root->left) &&
           isMaxOrder(root->right);
}

// Check Min-Heap property
bool isMinOrder(Node *root)
{
    if (root == NULL)
        return true;

    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
        return root->data < root->left->data;

    return (root->data < root->left->data) &&
           (root->data < root->right->data) &&
           isMinOrder(root->left) &&
           isMinOrder(root->right);
}

// Check if the tree is a Max Heap
bool checkMaxHeap(Node *root)
{
    int totalNodes = countNodes(root);
    return isCBT(root, 0, totalNodes) && isMaxOrder(root);
}

// Check if the tree is a Min Heap
bool checkMinHeap(Node *root)
{
    int totalNodes = countNodes(root);
    return isCBT(root, 0, totalNodes) && isMinOrder(root);
}

// Function to build a binary tree (Example: Preorder input with -1 as NULL)
Node *buildTree()
{
    int val;
    cin >> val;

    if (val == -1)
        return NULL;

    Node *root = new Node(val);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

int main()
{
    cout << "Enter elements of the tree (-1 for NULL nodes):" << endl;
    Node *root = buildTree();

    bool isMaxHeapOrder = checkMaxHeap(root);
    bool isMinHeapOrder = checkMinHeap(root);

    if (isMaxHeapOrder)
        cout << "Given Binary Tree is a Max Heap!" << endl;
    else if (isMinHeapOrder)
        cout << "Given Binary Tree is a Min Heap!" << endl;
    else
        cout << "Given Binary Tree is not a Heap!" << endl;

    return 0;
}
