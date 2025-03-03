#include <bits/stdc++.h>
using namespace std;

class twoStacks
{
private:
    int *arr; // Array to store stack elements
    int size; // Size of the array
    int top1; // Top index of Stack 1
    int top2; // Top index of Stack 2

public:
    // Constructor to initialize two stacks in one array
    twoStacks(int n = 100)
    {
        size = n;
        arr = new int[n]; //REVIEW - 
        top1 = -1;   // Stack 1 starts from the left end
        top2 = size; // Stack 2 starts from the right end
    }

    // Function to push an element into stack 1
    void push1(int x)
    {
        if (top1 < top2 - 1)
        { // Check if space is available
            arr[++top1] = x;
        }
    }

    // Function to push an element into stack 2
    void push2(int x)
    {
        if (top1 < top2 - 1)
        { // Check if space is available
            arr[--top2] = x;
        }
    }

    // Function to pop an element from stack 1
    int pop1()
    {
        if (top1 >= 0)
        { // Check if Stack 1 is not empty
            return arr[top1--];
        }
        return -1; // Stack 1 is empty
    }

    // Function to pop an element from stack 2
    int pop2()
    {
        if (top2 < size)
        { // Check if Stack 2 is not empty
            return arr[top2++];
        }
        return -1; // Stack 2 is empty
    }

    // Destructor to free memory
    ~twoStacks()
    {
        delete[] arr;
    }
};