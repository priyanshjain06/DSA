#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> stack; //  REVIEW string vector
        string part;
        stringstream ss(path);

        while (getline(ss, part, '/'))
        // ss => read , part => write  / => delimiter
        {
            if (part == "" || part == ".")
                continue;
            if (part == "..")
            {
                if (!stack.empty())
                    stack.pop_back(); // stack is string vector here  // Go up one directory
            }
            else
            {
                stack.push_back(part); // Valid directory/file eg ... is treadted as directory name !
            }
        }

        // REVIEW path should start and each dir should end with /
        string result = "/";
        for (int i = 0; i < stack.size(); ++i)
        {
            result += stack[i];
            if (i != stack.size() - 1)
                result += "/"; // for each  directory !
        }

        return result;
    }
};