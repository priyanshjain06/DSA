// NOTE there is one edge case that we  return when the  head is null
class Node
{
public:
    int data;
    Node *next;    // REVIEW
    Node(int data) // REVIEW -
    {
        this->data = data;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *head; // REVIEW
    int size;

public:
    Stack() // REVIEW
    {
        head = nullptr;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = head; // REVIEW
        head = newNode;
        size++; // REVIEW
    }

    void pop()
    {
        if (head == nullptr)
            return;
        Node *temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    int getTop()
    {
        return head == nullptr ? -1 : head->data;
    }
};
