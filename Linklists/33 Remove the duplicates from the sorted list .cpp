using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        // Dummy node to simplify deletion at head
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *prev = dummy; // last node before duplicates
        ListNode *curr = head;

        while (curr)
        {
            // Check if it's a beginning of a duplicate group
            if (curr->next && curr->val == curr->next->val)
            {
                int duplicateVal = curr->val;
                // Skip all nodes with this value
                while (curr && curr->val == duplicateVal)
                {
                    curr = curr->next;
                }
                prev->next = curr; // remove the group
            }
            else
            {
                // No duplication, just move pointers
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};
