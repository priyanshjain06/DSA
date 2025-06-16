#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1 || s.length() <= numRows)
            return s; // REVIEW

        vector<string> rows(min(numRows, int(s.length())));
        // REVIEW 
        //FIXME -

        int currRow = 0;
        bool goingDown = false;

        for (char c : s)
        {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1)
                goingDown = !goingDown;

            if (goingDown)
                currRow += 1;
            else
                currRow -= 1;
        }

        string result;
        for (string row : rows)
            result += row;
        return result;
    }
};
