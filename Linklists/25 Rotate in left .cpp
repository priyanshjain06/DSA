//LINK https://www.geeksforgeeks.org/problems/rotate-a-linked-list/1

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
        // Your code here
        if (head == nullptr || head->next == nullptr || k == 0) // REVIEW -
            return head;

        Node *temp = head;
        int length = 1; // REVIEW - 1 se start hoga

        // calculate the length of the list
        while (temp->next != nullptr)
        {
            ++length;
            temp = temp->next;
        }

        // link last node to first node
        temp->next = head;
        k = k % length;
        while (k--) //REVIEW 
            temp = temp->next;
        head = temp->next;
        temp->next = nullptr; // REVIEW -

        return head;
    }
};