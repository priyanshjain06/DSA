#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> left; // Max heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // Min heap (stores larger half)

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Insert number into appropriate heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Step 2: Balance the heaps
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0; // Even number of elements
        }
        return left.top(); // Odd number of elements
    }
};

// Driver code for testing
int main() {
    MedianFinder* obj = new MedianFinder();
    
    vector<int> nums = {5, 15, 1, 3};
    for (int num : nums) {
        obj->addNum(num);
        cout << "Median: " << obj->findMedian() << endl;
    }

    delete obj;
    return 0;
}
