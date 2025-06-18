#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;

        while (i < j) {
            int h = min(height[i], height[j]);
            int w = j - i;
            maxArea = max(maxArea, h * w);

            if (height[i] < height[j]) //REVIEW 
                i++;
            else
                j--;
        }

        return maxArea;
    }
};
