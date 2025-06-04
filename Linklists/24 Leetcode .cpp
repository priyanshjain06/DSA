class Node
{
public:
    int val;
    Node *prev;
    Node *next;
    Node *child;

    Node() : val(0), prev(nullptr), next(nullptr), child(nullptr) {}
    Node(int _val) : val(_val), prev(nullptr), next(nullptr), child(nullptr) {}
};

// REVIEW it is doubly linklist !

// LINK https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return nullptr;
        flattenDFS(head);
        return head;
    }

private:
    // Returns the tail after flattening list starting from 'node'
    Node *flattenDFS(Node *node)
    {
        Node *curr = node;
        Node *last = nullptr; // track last visited node in the flattened list

        while (curr)
        {
            Node *next = curr->next;

            // If child exists, flatten child list first
            if (curr->child)
            {
                Node *childTail = flattenDFS(curr->child);

                // Connect curr and child
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;

                // Connect child's tail with next node of the parent
                if (next)
                {
                    childTail->next = next;
                    next->prev = childTail;
                }

                last = childTail;
            }
            else
            {
                last = curr;
            }

            curr = next;
        }

        return last; // return tail of the flattened list
    }
};
