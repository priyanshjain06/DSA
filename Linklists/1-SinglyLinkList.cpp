#include <iostream>
#include <map>
using namespace std;
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int d)
{

    // new node create
    Node *temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    // new node create
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{

    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }
    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&tail, Node *&head, int position, int d)
{
    // insert at Start
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int cnt = 1;

    while (cnt < position - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // inserting at Last Position
    if (temp->next == NULL) // REVIEW -
    {
        insertAtTail(tail, d);
        return;
    }

    // creating a node for d
    Node *nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;

    temp->next = nodeToInsert;
}

void deleteNode(int position, Node *&head)
{

    // deleting first or start node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        // memory free start ndoe
        temp->next = NULL;
        delete temp;
    }
    else
    {
        // deleting any middle node or last node
        Node *curr = head;
        Node *prev = NULL;

        int cnt = 1;
        while (cnt < position) // REVIEW - position not pos -1
        {
            prev = curr;       // REVIEW -
            curr = curr->next; // REVIEW -
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

bool isCircularList(Node *head) // REVIEW
{
    // empty list
    if (head == NULL)
    {
        return true;
    }

    Node *temp = head->next; // REVIEW -
    while (temp != NULL && temp != head)
    {
        temp = temp->next;
    }

    if (temp == head)
    {
        return true;
    }

    return false;
}

bool detectLoop(Node *head)
{

    if (head == NULL)
        return false;

    map<Node *, bool> visited;

    Node *temp = head;

    while (temp != NULL)
    {

        // cycle is present
        if (visited[temp] == true)
        {
            cout << "Present on element " << temp->data << endl;
            return true;
        }

        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

Node *floydDetectLoop(Node *head)
{
    if (head == NULL)
        return NULL;

    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {                            // Fix: Ensure fast->next is valid
        slow = slow->next;       // Move slow by 1 step
        fast = fast->next->next; // Move fast by 2 steps

        if (slow == fast)
        { // Cycle detected
            cout << "Loop detected at node with value: " << slow->data << endl;
            return slow;
        }
    }

    return NULL; // No loop found
}

Node *getStartingNode(Node *head)
{

    if (head == NULL)
        return NULL;

    Node *intersection = floydDetectLoop(head);
    if (intersection == NULL)
        return NULL; // No cycle

    Node *slow = head;

    while (slow != intersection)
    {
        slow = slow->next;
        intersection = intersection->next;
    }

    return slow;
}

void removeLoop(Node *head) // REVIEW
{

    if (head == NULL)
        return;

    Node *startOfLoop = getStartingNode(head);
    Node *temp = startOfLoop;

    while (temp->next != startOfLoop)
    {
        temp = temp->next;
    }

    temp->next = NULL;
}