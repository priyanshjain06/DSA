class Solution
{
public:
    // REVIEW -  we need to check for consecutive elements only  here !
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 2)
            return n;

        int j = 2; // REVIEW  Start writing from the 3rd position
        for (int i = 2; i < n; ++i)
        {
            if (nums[i] != nums[j - 2])
            {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};
