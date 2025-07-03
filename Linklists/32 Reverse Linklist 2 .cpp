using namespace std;

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        if (!head || left == right) // REVIEW
            return head;

        // Dummy node to simplify edge cases
        ListNode *dummy = new ListNode(0);
        dummy->next = head; // REVIEW

        // Step 1: Reach the node before `left`
        ListNode *prev = dummy;
        for (int i = 1; i < left; ++i) // REVIEW from 1 since dummy node 
        {
            prev = prev->next;
        }

        // Step 2: Start reversing from `left` to `right`
        ListNode *curr = prev->next;
        ListNode *next = nullptr;
        for (int i = 0; i < right - left; ++i) //REVIEW - 
        {
            next = curr->next;       // next = 3
            curr->next = next->next; // curr->next = 4
            next->next = prev->next; // next->next = 2
            prev->next = next;       // prev->next = 3
        }

        return dummy->next; // REVIEW -
    }
};
