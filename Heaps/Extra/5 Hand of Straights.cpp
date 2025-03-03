#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0) //REVIEW - 
            return false; // Quick check

        unordered_map<int, int> freq;                           // Frequency map to count each card
        priority_queue<int, vector<int>, greater<int>> minHeap; // Min-Heap to process cards in sorted order

        // Step 1: Count frequency of each card
        for (int card : hand)
        {
            freq[card]++;
        }

        // Step 2: Push all unique numbers into minHeap
        for (auto [num, count] : freq) //REVIEW -  
        {
            minHeap.push(num);
        }

        // Step 3: Try forming groups
        while (!minHeap.empty())
        {
            int first = minHeap.top(); // Get smallest available number

            // Try to create a group of `groupSize` starting from `first`
            for (int i = 0; i < groupSize; i++)
            {
                int card = first + i;
                if (freq[card] == 0) //REVIEW - 
                    return false; // If any card is missing, return false

                freq[card]--; // Use one card

                // Remove from heap if frequency becomes zero or number is same at heap top
                if (freq[card] == 0 && minHeap.top() == card) //REVIEW - 
                {
                    minHeap.pop();
                }
            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> hand = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    int groupSize = 3;
    cout << "Can form groups: " << (sol.isNStraightHand(hand, groupSize) ? "Yes" : "No") << endl;
    return 0;
}
