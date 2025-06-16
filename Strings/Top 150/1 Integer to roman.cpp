// REVIEW Time and Space o(1) :

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    string intToRoman(int num)
    {
        vector<pair<int, string>> valueSymbol = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};
            
        // REVIEW  remember cm cd xc xl ix iv

        string result;
        for (const auto &[value, symbol] : valueSymbol) // REVIEW const
        {
            while (num >= value)
            {
                result += symbol;
                num -= value;
            }
        }
        return result;
    }
};
