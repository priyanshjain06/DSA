// NOTE restrications are: you can select middle element ,You can only select from left and right consecutively !

#include <iostream>
#include <vector>
using namespace std;

int maxPoints(vector<int> &nums, int k)
{
    int n = nums.size();
    int leftSum = 0, rightSum = 0, maxSum = 0;
    
    for (int i = 0; i < k; i++) //REVIEW -  
    {
        leftSum += nums[i];
    }

    maxSum = leftSum;

    int rightIndex = n - 1;
    for (int i = k - 1; i >= 0; i--) //REVIEW -  k-1 
    {
        leftSum = leftSum - nums[i];
        rightSum = rightSum + nums[rightIndex];
        maxSum = max(maxSum, leftSum + rightSum);
    }

    return maxSum;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 1}; // Example input
    int k = 3;                                // Number of elements to select
    cout << "Maximum points you can collect: " << maxPoints(nums, k) << endl;
    return 0;
}
