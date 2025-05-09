// REVIEW - Time Complexity : O(n ^2) and Space Compexity : O(n)

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fact = 1;
        vector<int> numbers;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans = "";
        k = k - 1; // zero based indexing of vector data -structure
        while (true)
        {
            ans = ans + to_string(numbers[k / fact]); //REVIEW convert to string
            numbers.erase(numbers.begin() + k / fact);
            if (numbers.size() == 0)
            {
                break;
            }
            // to calculate next factorial
            k = k % fact;
            fact = fact / numbers.size();
        }
        return ans;
    }
};
int main()
{
    int n = 3, k = 3;
    Solution obj;
    string ans = obj.getPermutation(n, k);
    cout << "The Kth permutation sequence is " << ans << endl;

    return 0;
}