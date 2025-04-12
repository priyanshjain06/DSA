// Example : hello world => world hello
// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

#include <iostream>
#include <string>
using namespace std;
string result(string s)
{
    int left = 0;
    int right = s.length() - 1;

    string temp = "";
    string ans = "";

    // Iterate the string and keep on adding to form a word
    // If empty space is encountered then add the current word to the result
    while (left <= right)
    {
        char ch = s[left];
        if (ch != ' ')
        {
            temp += ch;
        }
        else if (ch == ' ')
        {
            if (ans != "") // for 2 concescutive spaces
                ans = temp + " " + ans;
            else
                ans = temp;
            temp = ""; // REVIEW RESET
        }
        left++;
    }

    // If not empty string then add to the result(Last word is added)
    if (temp != "")
    {
        if (ans != "")
            ans = temp + " " + ans;
        else
            ans = temp;
    }
    return ans;
}
int main()
{
    string st = "TUF is great for interview preparation";
    cout << "Before reversing words: " << endl;
    cout << st << endl;
    cout << "After reversing words: " << endl;
    cout << result(st);
    return 0;
}