#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};
class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        if (!head || !head->next)
            return head; // Edge case: Empty list or single node list

        Node *curr = head;

        while (curr && curr->next)
        {
            if (curr->data == curr->next->data)
            {
                // Remove the duplicate node
                Node *duplicate = curr->next;
                curr->next = duplicate->next;

            if (duplicate->next) //REVIEW If not the last node
                    duplicate->next->prev = curr;

                delete duplicate; // Free memory
            }
            else
            {
                curr = curr->next; // Move to the next node
            }
        }

        return head;
    }
};
