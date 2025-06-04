// User function Template for C++
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
    Node *partition(Node *head, int x)
    {
        // Dummy nodes for three partitions
        Node *lessHead = new Node(0);
        Node *equalHead = new Node(0);
        Node *greaterHead = new Node(0);

        // Tail pointers for each partition
        Node *less = lessHead;
        Node *equal = equalHead;
        Node *greater = greaterHead;

        // Traverse and partition the nodes
        while (head != nullptr)
        {
            if (head->data < x)
            {
                less->next = head;
                less = less->next;
            }
            else if (head->data == x) //REVIEW 
            {
                equal->next = head;
                equal = equal->next;
            }
            else
            {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }

        // Terminate all lists
        greater->next = nullptr; //REVIEW - 
        equal->next = greaterHead->next;
        less->next = equalHead->next;

        // Final head is the start of the less-than-x list
        Node *result = lessHead->next;

        // Clean up dummy nodes
        delete lessHead;
        delete equalHead;
        delete greaterHead;

        return result;
    }
};
