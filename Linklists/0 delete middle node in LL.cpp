class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        if (!head || !head->next)
            return nullptr; // Edge case: Single node list

        ListNode *slow = head, *fast = head, *prev = nullptr; //REVIEW - 

        while (fast && fast->next)
        {
            prev = slow; //REVIEW Track the node before middle
            slow = slow->next;
            fast = fast->next->next;
        }

        prev->next = slow->next; //REVIEW -  // Skip the middle node
        delete slow;            //REVIEW -   // Free memory

        return head;
    }
};
