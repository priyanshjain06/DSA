// REVIEW example : hello world => world hello
#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    void reverseWords(string &str)
    {
        int n = str.length();

        // Reverse the entire string first
        reverse(str.begin(), str.end()); // REVIEW
         

        // Reverse each word in the reversed string
        int start = 0;
        for (int end = 0; end <= n; ++end)
        {
            if (end == n || str[end] == ' ')
            {
                reverse(str.begin() + start, str.begin() + end);
                start = end + 1;
            }
        }
    }
};
int main()
{
    Solution solution;
    string str = "hello world";
    solution.reverseWords(str);
    cout << str << endl; // Output: "world hello"
    return 0;
}
