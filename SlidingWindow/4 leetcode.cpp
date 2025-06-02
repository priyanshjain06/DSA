// REVIEW k is not given here so take  2 !

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int n = fruits.size();
        int maxlen = 0;
        int left = 0;
        int right = 0;

        map<int, int> map;

        while (right < n)
        {
            map[fruits[right]]++;

            if (map.size() > 2) // REVIEW -
            {
                map[fruits[left]]--;
                if (map[fruits[left]] == 0)
                {
                    map.erase(fruits[left]);
                }
                left++;
            }
            if (map.size() <= 2)
            {
                maxlen = max(maxlen, right - left + 1);
            }
            right++;
        }
        return maxlen;
    }
};