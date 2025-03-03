    #include <iostream>
    #include <vector>
    #include <string>
    using namespace std;

    class Solution
    {
    public:
        string longestPalindrome(string s)
        {
            string t = preprocess(s); // REVIEW returns a string
            int n = t.length();
            vector<int> p(n, 0); // Array to store the length of the palindrome radius
            int c = 0, r = 0;    // Current center and right boundary

            for (int i = 1; i < n - 1; i++) // REVIEW starts from 1
            {
                int mirr = 2 * c - i; // Mirror of the current position

                if (i < r)
                {
                    p[i] = min(r - i, p[mirr]);
                }

                // Expand around the current center // REVIEW if equal to prefix
                while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                {
                    p[i]++;
                }

                // Update the center and right boundary
                if (i + p[i] > r)
                {
                    c = i;
                    r = i + p[i];
                }
            }

            // Find the maximum element in p
            int maxLen = 0;
            int centerIndex = 0;
            for (int i = 1; i < n - 1; i++) // REVIEW stars from 1
            {
                if (p[i] > maxLen)
                {
                    maxLen = p[i];
                    centerIndex = i;
                }
            }

            int start = (centerIndex - maxLen) / 2;
            return s.substr(start, maxLen);
        }

    private:
        string preprocess(const string &s) // STUB -  Manacher's Algorithm,
        {
            string t = "^";
            for (char c : s)
            {
                t += "#" + string(1, c);
            }
            t += "#$";
            return t;
        }
    };
