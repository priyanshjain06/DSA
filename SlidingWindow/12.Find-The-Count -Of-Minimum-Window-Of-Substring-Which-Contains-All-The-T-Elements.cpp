    #include <iostream>
    #include <unordered_map>
    #include <climits>
    using namespace std;

    class Solution
    {
    public:
        string minWindow(string s, string t)
        {
            unordered_map<char, int> required; //REVIEW - 
            int count = 0, min_length = INT_MAX, start_index = -1;

            for (char c : t)
            {
                required[c]++;
            }

            int left = 0;
            for (int right = 0; right < s.length(); right++)
            {
                if (required.find(s[right]) != required.end())
                {
                    required[s[right]]--;
                    if (required[s[right]] >= 0)
                    {
                        count++;
                    }
                }

                while (count == t.length()) //REVIEW 
                {
                    int window_length = right - left + 1;
                    if (window_length < min_length)
                    {
                        min_length = window_length;
                        start_index = left;
                    }

                    if (required.find(s[left]) != required.end())
                    {
                        if (required[s[left]] == 0)
                        {
                            count--;
                        }
                        required[s[left]]++;
                    }
                    left++;
                }
            }
            return (start_index == -1) ? "" : s.substr(start_index, min_length); //REVIEW - 
        }
    };

    int main()
    {
        Solution sol;
        string s = "ADOBECODEBANC";
        string t = "ABC";
        cout << "Minimum window substring: " << sol.minWindow(s, t) << endl;
        return 0;
    }
