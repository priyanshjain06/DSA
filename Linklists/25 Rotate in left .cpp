// LINK https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        // REVIEW we write this based on constraints
        if (head == nullptr || head->next == nullptr || k == 0) // REVIEW -
            return head;

        Node *temp = head;
        int length = 1; // REVIEW - 1 se start hoga

        // calculate the length of the list
        while (temp->next != nullptr) // REVIEW we are not traversing last node , so we start with 1 as count
        {
            ++length;
            temp = temp->next;
        }

        // link last node to first node
        temp->next = head;
        k = k % length;
        while (k--)            // REVIEW
            temp = temp->next; // temp is at 2 node k=2
        head = temp->next;     // head is at 3 node
        temp->next = nullptr;  // REVIEW - temp is 2 whose next is null

        return head;
    }
};