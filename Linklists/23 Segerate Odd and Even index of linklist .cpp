struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
    
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return nullptr; // Edge case: Empty list

        // Dummy nodes for odd and even lists
        ListNode *oddDummy = new ListNode(-1), *oddTail = oddDummy;
        ListNode *evenDummy = new ListNode(-1), *evenTail = evenDummy;

        ListNode *curr = head;
        int index = 1; // 1-based index //REVIEW

        while (curr)
        {
            ListNode *temp = curr;
            curr = curr->next;    // REVIEW -
            temp->next = nullptr; // Break the current node’s link

            if (index % 2 == 1)
            { // Odd index
                oddTail->next = temp;
                oddTail = temp;
            }
            else
            { // Even index
                evenTail->next = temp;
                evenTail = temp;
            }
            index++;
        }

        oddTail->next = evenDummy->next; // Append even list after odd list
        return oddDummy->next;           // Return the new head (oddDummy->next)
    }
};
