// EXample : priya jain => priya@40jain
// NOTE replace with @40

#include <iostream>
#include <string>
using namespace std;

string replaceSpaces(string &str)
{
    string temp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else
        {
            temp.push_back(str[i]);
        }
    }
    return temp;
}