#include <iostream>
#include <queue>
#include <map>
using namespace std;

// Definition of Binary Tree Node
class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left;
    BinaryTreeNode *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// Function to map parent nodes and find the target node
BinaryTreeNode *bfsToMapParents(BinaryTreeNode *root, map<BinaryTreeNode *, BinaryTreeNode *> &mpp, int start) // REVIEW
{
    queue<BinaryTreeNode *> q;
    q.push(root);
    BinaryTreeNode *res = nullptr; // REVIEW

    while (!q.empty())
    {
        BinaryTreeNode *node = q.front();
        q.pop();

        if (node->data == start) // REVIEW
            res = node;          // REVIEW

        if (node->left)
        {
            mpp[node->left] = node;
            q.push(node->left);
        }

        if (node->right)
        {
            mpp[node->right] = node;
            q.push(node->right);
        }
    }
    return res; //REVIEW
}

// Function to calculate the maximum distance to burn the tree
int findMaxDistance(map<BinaryTreeNode *, BinaryTreeNode *> &mpp, BinaryTreeNode *target)
{
    queue<BinaryTreeNode *> q; // REVIEW
    q.push(target);
    map<BinaryTreeNode *, int> vis; // REVIEW not undored map
    vis[target] = 1;

    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;

        for (int i = 0; i < sz; i++)
        {
            BinaryTreeNode *node = q.front(); // REVIEW
            q.pop();                          // REVIEW

            if (node->left && !vis[node->left])
            {
                fl = 1;
                vis[node->left] = 1;
                q.push(node->left);
            }

            if (node->right && !vis[node->right])
            {
                fl = 1;
                vis[node->right] = 1;
                q.push(node->right);
            }

            if (mpp[node] && !vis[mpp[node]])
            {
                fl = 1;
                vis[mpp[node]] = 1;
                q.push(mpp[node]);
            }
        }

        if (fl)
            maxi++;
    }
    return maxi;
}

// Main function to calculate the time to burn the binary tree
int timeToBurnTree(BinaryTreeNode *root, int start)
{
    map<BinaryTreeNode *, BinaryTreeNode *> mpp;
    BinaryTreeNode *target = bfsToMapParents(root, mpp, start); // REVIEW
    int maxi = findMaxDistance(mpp, target); //REVIEW
    return maxi; //REVIEW 
}
