//

#include <iostream>
#include <string>
using namespace std;
class Solution
{
public:
    string largestOddNumber(string num)
    {
        for (int i = num.length() - 1; i >= 0; i--) // REVIEW  i--
        {
            if ((num[i]) % 2 == 1)
            {
                return num.substr(0, i + 1);
            }
        }
        return ""; // REVIEW -
    }
};