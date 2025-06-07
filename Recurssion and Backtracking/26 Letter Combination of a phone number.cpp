#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    void backtrack(int index, string &input, string &current, vector<string> &result, vector<string> &mapping)
    {
        if (index == input.size())
        { // Base case: If we have processed all digits
            result.push_back(current);
            return;
        }

        string letters = mapping[input[index] - '2']; // REVIEW  Get letters for current digit
        for (char ch : letters)
        {
            current.push_back(ch);                                 // Choose a letter
            backtrack(index + 1, input, current, result, mapping); // Recurse
            current.pop_back();                                    // Undo choice (Backtrack)
        }
    }

    vector<string> letterCombinations(string input) // REVIEW
    {
        if (input.empty()) // REVIEW
            return {};     // Edge case: If input is empty

        vector<string> mapping = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; // REVIEW 0 and 1 are not included
        vector<string> result;
        string current;

        backtrack(0, input, current, result, mapping);
        return result;
    }
};

int main()
{
    Solution sol;
    string input = "23"; // Changed "digits" to "input"
    vector<string> result = sol.letterCombinations(input);

    // Print result
    for (const string &comb : result)
    {
        cout << comb << " ";
    }
    return 0;
}
