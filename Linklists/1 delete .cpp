class Solution
{
public:
    void deleteNode(ListNode *node) // node is the value which is to be deleted
    {
        node->val = node->next->val;   // Copy value of next node to current node
        node->next = node->next->next; // Delete the next node
    }
};
