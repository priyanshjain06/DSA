#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a binary tree node
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
    // Map parents of each node for traversal
    void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent_map)
    {
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left)
            {
                parent_map[current->left] = current;
                q.push(current->left);
            }
            if (current->right)
            {
                parent_map[current->right] = current;
                q.push(current->right);
            }
        }
    }

public:
    // Function to calculate time to burn the binary tree
    int burnTree(TreeNode *root, TreeNode *target)
    {
        unordered_map<TreeNode *, TreeNode *> parent_map; // Map to store parent pointers
        markParents(root, parent_map);

        unordered_map<TreeNode *, bool> visited; // Track visited nodes
        queue<TreeNode *> q;                     // BFS queue
        q.push(target);
        visited[target] = true;

        int time = 0; // Keeps track of the time taken to burn the tree //REVIEW 

        while (!q.empty())
        {
            int size = q.size();
            bool burn_next = false; // Indicates if the next level burns //REVIEW 

            for (int i = 0; i < size; i++)
            {
                TreeNode *current = q.front();
                q.pop();

                // Check left child
                if (current->left && !visited[current->left])
                {
                    q.push(current->left);
                    visited[current->left] = true;
                    burn_next = true;
                }

                // Check right child
                if (current->right && !visited[current->right])
                {
                    q.push(current->right);
                    visited[current->right] = true;
                    burn_next = true;
                }

                // Check parent node
                if (parent_map[current] && !visited[parent_map[current]])
                {
                    q.push(parent_map[current]);
                    visited[parent_map[current]] = true;
                    burn_next = true;
                }
            }

            // Increment time if any node burns at this level
            if (burn_next)
            {
                time++;
            }
        }

        return time;
    }
};

int main()
{
    // Example usage
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution solution;
    TreeNode *target = root->left; // Target node to start burning
    int timeToBurn = solution.burnTree(root, target);
    cout << "Time to burn the binary tree: " << timeToBurn << endl;

    return 0;
}
