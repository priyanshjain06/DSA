// REVIEW  Time Complexity: O(n)
// NOTE example : priya jain => ayirp niaj

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


int main()
{
    string str = "Hello, world!";
    reverse(str.begin(), str.end());
    cout << "Reversed string: " << str << endl;
    return 0;
}

// REVIEW -  for leetcode


// class Solution {
// public:
//     void reverseString(vector<char>& s) {
//         int left = 0;
//         int right = s.size() - 1;

//         while (left < right) {
//             swap(s[left], s[right]); //REVIEW -
//             left++;
//             right--;
//         }
//     }
// };

// REVIEW  or use a stack (**NOT optimal ***)
