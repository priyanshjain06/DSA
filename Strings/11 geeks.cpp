class Solution
{
public:
    void backtrack(string &s, vector<string> &result, int index)
    {
        if (index == s.size())
        {
            result.push_back(s);
            return;
        }

        unordered_set<char> used;
        for (int i = index; i < s.size(); ++i)
        {
            if (used.count(s[i]))
                continue;

            used.insert(s[i]);
            swap(s[i], s[index]);
            backtrack(s, result, index + 1);
            swap(s[i], s[index]); // backtrack
        }
    }

    vector<string> findPermutation(string &s)
    {
        vector<string> result;
        backtrack(s, result, 0);
        return result;
    }
};
