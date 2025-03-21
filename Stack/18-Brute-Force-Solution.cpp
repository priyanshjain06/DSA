#include <stack>
#include <limits.h>
using namespace std ;
class MinStack {
private:

    std::stack<int> stack;
    std::stack<int> minStack;
    
public:
    MinStack() {}
    
    void push(int val) {
        stack.push(val);
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }
    
    void pop() {
        if (!stack.empty()) {
            if (stack.top() == minStack.top()) {
                minStack.pop();
            }
            stack.pop();
        }
    }
    
    int top() {
        return stack.empty() ? -1 : stack.top();
    }
    
    int getMin() {
        return minStack.empty() ? -1 : minStack.top();
    }
};

// Example usage:
// MinStack minStack;
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// cout << minStack.getMin(); // return -3
// minStack.pop();
// cout << minStack.top();    // return 0
// cout << minStack.getMin(); // return -2