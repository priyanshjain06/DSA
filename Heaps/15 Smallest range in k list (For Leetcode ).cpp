
class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>> &nums)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap; // REVIEW
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;
        
        // Step 1: Insert the first element of each list into the heap
        for (int i = 0; i < nums.size(); i++)
        {
            minHeap.push({nums[i][0], i, 0}); // {value, row index, col index}
            maxVal = max(maxVal, nums[i][0]);
        }

        // Step 2: Process heap until one list is exhausted
        while (!minHeap.empty())
        {
            auto top = minHeap.top();
            minHeap.pop();
            int minVal = top[0], row = top[1], col = top[2];//REVIEW - 
            // NOTE min heap store 3 things for each node value , row ,col
            // Update range if smaller range found
            if (maxVal - minVal < rangeEnd - rangeStart)
            {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }

            // Move to the next element in the same list
            if (col + 1 < nums[row].size())
            {
                int nextVal = nums[row][col + 1];
                minHeap.push({nextVal, row, col + 1});
                maxVal = max(maxVal, nextVal);
            }
            else //REVIEW - 
            {
                break; // Stop when one list is exhausted
            }
        }

        return {rangeStart, rangeEnd};
    }
};