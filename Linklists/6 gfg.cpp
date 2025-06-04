using namespace std;

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        if (head == NULL || k == 1)
            return head;

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;
        int count = 0;

        // Step 1: Reverse first k nodes or all remaining nodes
        curr = head;
        while (curr != NULL && count < k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // Step 2: Recur for the remaining list and connect
        if (next != NULL)
        {
            head->next = reverseKGroup(next, k); // `head` is the new tail after reversal
        }

        // Step 3: prev is the new head of the reversed group
        return prev;
    }
};