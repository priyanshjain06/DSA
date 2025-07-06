// NOTE :Problem Statement: Given a String, find the length of longest substring without any repeating character.

// ANCHOR Time Complexity: O( N ) and Space Complexity: O( N )

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    int lengthofLongestSubstring(string s)
    {

        int left = 0, right = 0;
        int n = s.size();
        int len = 0;
        vector<int> mpp(256, -1); // REVIEW -

        while (right < n)
        {
            if (mpp[s[right]] != -1 && mpp[s[right]] >= left)
                left = mpp[s[right]] + 1;

            mpp[s[right]] = right;
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};


int main()
{
    string str = "takeUforward";
    Solution obj;
    cout << "The length of the longest substring without repeating characters is " << obj.lengthofLongestSubstring(str);
    return 0;
}
