// NOTE Problem Statement: Given a linked list containing ‘N’ head nodes where every node in the linked list contains two pointers:
//  ‘Next’ points to the next node in the list
//  ‘Child’ pointer to a linked list where the current node is the head
//  Each of these child linked lists is in sorted order and connected by a 'child' pointer. Your task is to flatten this linked list such that all nodes appear in a single layer or level in a 'sorted order'.

// REVIEW - Two main things from question is that 1)all the child nodes are sorted and 2) we are given with head of the linklist

// ANCHOR : Time Complexity:  O(2 N*M) where N is no. of parent nodesand M is no. of child nodes
// Space Complexity : O(1)

// SECTION : Follow 3 steps :- 1) Create a dummy node. and check for basic condtions  2) Merge the lists. 3) Connect the list by using recursion

// LINK https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child; //REVIEW - 

    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

Node *merge(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        // REVIEW -
        if (list1->data < list2->data)
        {
            res->child = list1; 
            // here list1 means the  current node of the list1
            res = list1;
            list1 = list1->child; //REVIEW - 
        }
        else
        {
            res->child = list2;
            res = list2;
            list2 = list2->child;
        }
        res->next = NULL; // REVIEW -
    }


    // Connect the remaining
    // elements if any
    if (list1)
    {
        res->child = list1; // REVIEW -
    }
    else
    {
        res->child = list2;
    }

    // Break the last node's
    // link to prevent cycles
    // REVIEW -  we will mark all the next of nodes to null
    if (dummyNode->child)
    {
        dummyNode->child->next = NULL; //REVIEW - 
    }

    return dummyNode->child; 
}

Node *flattenLinkedList(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // REVIEW -
    Node *mergedHead = flattenLinkedList(head->next);
    head = merge(head, mergedHead);
    return head;
}

void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child; //REVIEW - 
    }
    cout << endl;
}

// REVIEW -  ignore this function
void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        if (head->next)
        {
            cout << endl;
            for (int i = 0; i < depth; ++i)
            {
                cout << "| ";
            }
        }
        head = head->next;
    }
}

int main()
{
    // Create a linked list with child pointers
    Node *head = new Node(5);
    head->child = new Node(14);

    head->next = new Node(10);
    head->next->child = new Node(4);

    head->next->next = new Node(12);
    head->next->next->child = new Node(20);
    head->next->next->child->child = new Node(13);

    head->next->next->next = new Node(7);
    head->next->next->next->child = new Node(17);

    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
