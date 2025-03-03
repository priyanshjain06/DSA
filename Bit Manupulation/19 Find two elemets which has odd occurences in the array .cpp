//// NOTE Given an unsorted array, Arr[] of size N and that contains even number of occurrences for all numbers except two numbers. Find the two numbers in decreasing order which has odd occurrences

// REVIEW -  Time Complexity : O(N) and Space Complexity : O(1)

// ANCHOR use gpt to understand the dry run

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void findTwoOddOccurrenceNumbers(const vector<int> &arr)
{
    // Step 1: XOR all elements to get the XOR of the two odd occurring numbers
    int xorResult = 0;
    for (int num : arr)
    {
        xorResult ^= num; // REVIEW compounded operator
    }

    // Step 2: Find the rightmost set bit (1st set bit) in xorResult
    int rightmostSetBit = xorResult & -xorResult;
    // -x means two complement here that is ~x+1

    // Step 3: Divide the array into two groups based on the rightmost set bit
    int num1 = 0, num2 = 0;
    {
        for (int i : arr)

            if (i & rightmostSetBit)
            {
                num1 ^= i; // Elements with the rightmost set bit
            }
            else
            {
                num2 ^= i; // Elements without the rightmost set bit
            }
    }
    // Step 4: Output the two numbers in decreasing order
    cout << "The two numbers with odd occurrences are: ";
    if (num1 > num2)
    {
        cout << num1 << " " << num2 << endl;
    }
    else
    {
        cout << num2 << " " << num1 << endl;
    }
}
int main()
{
    vector<int> arr = {4, 3, 4, 4, 5, 3, 3, 6}; // Example array
    findTwoOddOccurrenceNumbers(arr);           // Find and print the two odd occurrence numbers
    return 0;
}
