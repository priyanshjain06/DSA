class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        // Sort the greed factors (children's demand) in ascending order
        sort(g.begin(), g.end()); // REVIEW

        // Sort the cookie sizes in ascending order
        sort(s.begin(), s.end()); // REVIEW -

        int child = 0;  // Pointer for children
        int cookie = 0; // Pointer for cookies

        // Iterate through both arrays to satisfy as many children as possible
        while (child < g.size() && cookie < s.size())
        {
            // If the current child can be satisfied by the current cookie
            if (g[child] <= s[cookie])
            {
                child++; // REVIEW child is like l here
                // Move to the next child
            }
            // Always move to the next cookie
            cookie++;
        }

        // The number of satisfied children is represented by `child`
        return child;
    }
};