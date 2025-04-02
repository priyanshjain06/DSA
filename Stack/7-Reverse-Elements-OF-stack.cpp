#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    // Base case: If stack is empty, insert the element
    if (st.empty())
    {
        st.push(x);
        return;
    }

    // Step 1: Keep aside the top element
    int topElement = st.top();
    st.pop();

    // Step 2: Recursively insert at bottom
    insertAtBottom(st, x);

    // Step 3: Push back the stored element
    st.push(topElement);
}

void reverseStack(stack<int> &stack)
{
    // Base case: If stack is empty, return
    if (stack.empty())
    {
        return;
    }

    // Step 1: Remove the top element
    int num = stack.top();
    stack.pop();

    // Step 2: Recursively reverse the remaining stack
    reverseStack(stack); //REVIEW pehele khud ko fir dusro ko !

    // Step 3: Insert the removed element at the bottom
    insertAtBottom(stack, num);
}

// Driver Code
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << "Original Stack (Top to Bottom): ";
    stack<int> temp = st;
    while (!temp.empty())
    {
        cout << temp.top() << " ";
        temp.pop();
    }
    cout << endl;

    reverseStack(st);

    cout << "Reversed Stack (Top to Bottom): ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
