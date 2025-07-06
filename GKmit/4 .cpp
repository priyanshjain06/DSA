//REVIEW  Time Complexity :  O(nlogn) and Space Complexity : O(n)

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> strNums; //REVIEW 

        // Convert integers to strings
        for (int num : nums)
        {
            strNums.push_back(to_string(num));
        }

        // Custom comparator: which combination forms bigger number
        sort(strNums.begin(), strNums.end(), [](string a, string b)
             { return a + b > b + a; }); //FIXME - 

        // Edge case: all zeroes
        if (strNums[0] == "0")
            return "0";

        // Concatenate all strings
        string result;
        for (string &s : strNums) //REVIEW string &s or auto& s
        {
            result += s;
        }

        return result;
    }
};

