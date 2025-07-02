/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) { //REVIEW
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) { //REVIEW
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
    Node *cloneUtil(Node *node, unordered_map<Node *, Node *> &mp)
    {              // Node *
        
        if (!node) // edge case
            return NULL;

        Node *newNode = new Node(node->val);
        mp[node] = newNode;

        for (auto neighbor : node->neighbors)
        {
            if (mp.find(neighbor) == mp.end())
            {
                // create the neighbor's clone
                (newNode->neighbors).push_back(cloneUtil(neighbor, mp));
                // REVIEW  Recursively call it !
            }
            else
            {
                (newNode->neighbors).push_back(mp[neighbor]);
            }
        }
        return newNode;
    }
    Node *cloneGraph(Node *node)
    {
        unordered_map<Node *, Node *> mp; //  create a hashamp for marking old - new
        return cloneUtil(node, mp);
    }
};