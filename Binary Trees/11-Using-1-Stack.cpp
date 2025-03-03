#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root)
{
    vector<int> postorder;
    if (!root) 
        return postorder;

    stack<TreeNode *> st;
    TreeNode *curr = root;

    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            TreeNode *temp = st.top()->right;
            if (temp == NULL) //REVIEW 
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->val);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}

// Helper function to create a tree node
TreeNode *createNode(int val)
{
    return new TreeNode(val);
}

// Example usage
int main()
{
    TreeNode *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    vector<int> result = postorderTraversal(root);
    for (int val : result)
    {
        cout << val << " ";
    }
    return 0;
}
