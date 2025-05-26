// REVIEW REFER To linklist
// NOTE - A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to check if a string is a valid palindrome
bool isPalindrome(string s)
{
    int left = 0, right = s.length() - 1;

    while (left < right)
    {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left]))
        {
            left++;
        }

        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right]))
        {
            right--;
        }

        // Compare characters (case insensitive)
        if (tolower(s[left]) != tolower(s[right]))
        {
            return false;
        }

        left++; 
        right--;
    }
    return true; //REVIEW 
}

int main()
{
    string s = "A man, a plan, a canal: Panama";
    cout << (isPalindrome(s) ? "True" : "False") << endl; // Output: True
    return 0;
}
