class Solution
{
public:
    void backtrack(int start, int n, int k, vector<int> &current, vector<vector<int>> &ans)
    {
        if (current.size() == k)
        {
            ans.push_back(current);
            return;
        }

        for (int i = start; i <= n; ++i)
        {
            current.push_back(i);                 // ✅ Pick
            backtrack(i + 1, n, k, current, ans); // 🔁 Recursive call
            current.pop_back();                   // ❌ Backtrack (Not Pick)
        }
    }

    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(1, n, k, current, ans);
        return ans;
    }
};
