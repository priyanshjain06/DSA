#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string result = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';

                // '1' - '0' = 49- 48 = 1 

            result += (sum % 2) + '0'; // add binary digit
            carry = sum / 2;           // carry for next digit
        }

        reverse(result.begin(), result.end()); //REVIEW - 
        return result;
    }
};
