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
    ListNode *partition(ListNode *head, int x)
    {
        // Dummy heads for less and greater/equal lists
        ListNode *lessHead = new ListNode(0);
        ListNode *greaterHead = new ListNode(0);

        ListNode *less = lessHead;
        ListNode *greater = greaterHead;

        while (head != nullptr)
        {
            if (head->val < x)
            {
                less->next = head;
                less = less->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Important: end the greater list
        greater->next = nullptr;
        // Connect less list to greater list
        less->next = greaterHead->next;

        ListNode *result = lessHead->next; // REVIEW

        // Free dummy nodes
        delete lessHead;
        delete greaterHead;

        return result;
    }
};