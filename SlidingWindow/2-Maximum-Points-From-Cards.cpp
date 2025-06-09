// NOTE restrications are: you can select middle element ,You can only select from left and right consecutively !

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int leftSum = 0, rightSum = 0, maxSum = 0;

        // Take all k cards from the left initially
        for (int i = 0; i < k; i++)
        {
            leftSum += cardPoints[i];
        }

        maxSum = leftSum;

        int rightIndex = n - 1;
        // Try taking i cards from the left and k - i cards from the right
        for (int i = k - 1; i >= 0; i--) //REVIEW 
        {
            leftSum -= cardPoints[i];             // remove one from left
            rightSum += cardPoints[rightIndex--]; // REVIEW  add one from right
            maxSum = max(maxSum, leftSum + rightSum);
        }

        return maxSum;
    }
};