class Solution
{
public:
    // Recursive function to remove the middle element
    void deleteMiddleHelper(stack<int> &s, int current, int mid) 
    {
        // Base case: When we reach the middle element, remove it
        if (current == mid) //REVIEW  
        {
            s.pop();
            return;
        }

        // Store the top element
        int topElement = s.top();
        s.pop();

        // Recursive call to go deeper into the stack
        deleteMiddleHelper(s, current + 1, mid);

        // Push the element back after deleting the middle
        s.push(topElement);
    }

    // Function to delete the middle element of a stack
    void deleteMid(stack<int> &s)
    {
        if (s.empty())
            return;

        int mid = s.size() / 2; // Correct middle element index (0-based)
        deleteMiddleHelper(s, 0, mid); //REVIEW - current is passed as 0
    }
};