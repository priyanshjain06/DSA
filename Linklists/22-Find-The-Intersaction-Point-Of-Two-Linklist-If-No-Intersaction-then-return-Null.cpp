// NOTE : Problem Statement: Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

// REVIEW -  Remember the give two linklist will be of Y type Linklist

// ANCHOR :- Time Complexity: O(2*max(length of list1,length of list2)) and Space Complexity: O(1)

// LINK -

#include <iostream>
#include <map>
using namespace std;

class node
{
public:
    int num;
    node *next;
    node(int val)
    {
        num = val;
        next = NULL;
    }
};
// utility function to insert node at the end of the linked list

// utility function to check presence of intersection
node *findIntersection(node *head1, node *head2)
{
    node *d1 = head1, *d2 = head2;

    while (d1 != d2)
    {
        if (d1 == nullptr)
        {
            d1 = head2;
        }
        else
        {
            d1 = d1->next;
        }

        if (d2 == nullptr)
        {
            d2 = head1;
        }
        else
        {
            d2 = d2->next;
        }
    }

    return d1; // REVIEW Returns intersection node or NULL if no intersection
}
