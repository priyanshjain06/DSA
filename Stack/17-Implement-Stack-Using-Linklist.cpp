#include <iostream>
using namespace std;
class StackNode
{
public:
    int data;
    StackNode *next;

    StackNode(int d)
    {
        data = d;
        next = nullptr;
    }
};
class Stack
{
private:
    StackNode *top;
    int size;

public:
    // Constructor to initialize the stack
    Stack() //REVIEW -
    {
        top = nullptr;
        size = 0;
    }
    // Push an element onto the stack
    void push(int x)
    {
        StackNode *element = new StackNode(x);
        element->next = top;
        top = element;
        cout << "Element pushed" << "\n";
        size++;
    }

    // Pop an element from the stack
    int pop()
    {
        if (top == nullptr)
        {
            return -1; // Return -1 if the stack is empty
        }
        int topData = top->data;
        StackNode *temp = top;
        top = top->next;
        delete temp;
        size--; //REVIEW - 
        return topData;
    }

    // Get the size of the stack
    int getSize()
    {
        return size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Peek at the top element of the stack
    int peek()
    {
        if (top == nullptr)
            return -1; // Return -1 if the stack is empty
        return top->data;
    }

    // Print all elements of the stack
    void printStack()
    {
        StackNode *current = top;
        while (current != nullptr)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};

int main()
{
    Stack s;
    s.push(10);
    cout << "Element popped: " << s.pop() << "\n";
    cout << "Stack size: " << s.getSize() << "\n";
    cout << "Stack empty or not? " << s.isEmpty() << "\n";
    cout << "Stack's top element: " << s.peek() << "\n";

    return 0;
}
