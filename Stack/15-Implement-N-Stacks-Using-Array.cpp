// NOTE -

// ANCHOR -  Time Complexity - O(1) and Space Compexity - O(N+S) where N is number of stacks and S is size of stack

// LINK Remember two edge cases :
//  what does next do
//  and
//  make last index of next array -1

#include <iostream>
#include <vector>
using namespace std;
class NStack
{
    int *arr; // REVIEW * is used to declare pointers
    int *top;
    int *next;

    int n, s;

    int freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        n = N; // n is number of stacks to be implemented
        s = S; // s is the size  of the array
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialise
        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        // next initialise
        for (int i = 0; i < s; i++)
        {
            next[i] = i + 1;
        }

        // update last index value to -1
        next[s - 1] = -1; // REVIEW -

        // initialise freespot
        freespot = 0; // REVIEW -
    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if (freespot == -1)
        {
            return false;
        }

        // find index
        int index = freespot;

        // insert element into array
        arr[index] = x;

        // update freespot
        freespot = next[index];

        // update next;
        next[index] = top[m - 1]; // REVIEW m represents the stack number in which we are performing operations.

        // update top
        top[m - 1] = index;

        return true; // REVIEW
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // REVIEW  check underflow condition
        if (top[m - 1] == -1)
        {
            return -1;
        }

        int index = top[m - 1];

        top[m - 1] = next[index];

        next[index] = freespot;

        freespot = index;

        return arr[index]; // REVIEW
    }
};