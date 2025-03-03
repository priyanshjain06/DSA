// ANCHOR : Time Complexity:  O(N*M) + O(N*M log(N*M))  where N is no. of parent nodesand M is no. of child nodes
// Space Complexity : O(N*M) + O(N*M)

//LINK : we create a vector which store all the child nodes of each parent node and we move the parent node to next parent node till null  and then sort the vector and finally we convert the vector into linked list

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr) {};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *nextNode, Node *childNode) : data(x), next(nextNode), child(childNode) {}
};

Node *convertArrToLinkedList(vector<int> &arr)
{
    Node *dummyNode = new Node(-1);
    Node *temp = dummyNode;

    for (int i = 0; i < arr.size(); i++) //REVIEW -  start from 0
    {
        temp->child = new Node(arr[i]);
        temp = temp->child;
    }
    return dummyNode->child;
}

Node *flattenLinkedList(Node *head)
{
    vector<int> arr; //REVIEW - 

    while (head != nullptr)
    {

        Node *parentNode = head;
        while (parentNode != nullptr)
        {
            arr.push_back(parentNode->data);
            parentNode = parentNode->child;
        }
        head = head->next;
    }

    sort(arr.begin(), arr.end());

    return convertArrToLinkedList(arr); //REVIEW - 
}

// Print the linked list by
// traversing through child pointers
void printLinkedList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->child;
    }
    cout << endl;
}

// Print the linked list
// in a grid-like structure
void printOriginalLinkedList(Node *head, int depth)
{
    while (head != nullptr)
    {
        cout << head->data;

        // If child exists, recursively
        // print it with indentation
        if (head->child)
        {
            cout << " -> ";
            printOriginalLinkedList(head->child, depth + 1);
        }

        // Add vertical bars
        // for each level in the grid
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

    // Print the original
    // linked list structure
    cout << "Original linked list:" << endl;
    printOriginalLinkedList(head, 0);

    // Flatten the linked list
    // and print the flattened list
    Node *flattened = flattenLinkedList(head);
    cout << "\nFlattened linked list: ";
    printLinkedList(flattened);

    return 0;
}
