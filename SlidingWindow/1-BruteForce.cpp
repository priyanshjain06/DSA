// NOTE :Problem Statement: Given a String, find the length of longest substring without any repeating character.

// ANCHOR Time Complexity: O( N^2 )

#include <iostream>
#include <unordered_set> //REVIEW -
using namespace std;
int solve(string str)
{
    if (str.size() == 0)
        return 0;

    int maxans = INT_MIN;
    for (int i = 0; i < str.length(); i++)
    // outer loop for traversing the string
    {
        unordered_set<int> set; // or use a hash[256]
        for (int j = i; j < str.length(); j++) // nested loop for getting different string starting with str[i]
        {
            if (set.find(str[j]) != set.end()) //if  hash[str[j]==1] break;
            // if element if found so mark it as ans and break from the loop
            {
                maxans = max(maxans, j - i);
                break;
            }

            set.insert(str[j]);
        }
    }
    return maxans;
}

int main()
{
    string str = "takeUforward";
    cout << "The length of the longest substring without repeating characters is " << solve(str);
    return 0;
}