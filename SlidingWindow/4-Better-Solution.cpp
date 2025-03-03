#include <iostream>
#include <map>
using namespace std;

int findLongestSubarray(int n, int k, int num[]) {
    int maxLen = 0;
    int left = 0;
    int right = 0;
    
    map<int, int> freq; // Rename variable to avoid confusion

    while (right < n) {
        freq[num[right]]++; // Increase count of current element

        // Shrink the window if we exceed k distinct elements
        while (freq.size() > k) {
            freq[num[left]]--; // Reduce count of leftmost element
           if (freq[num[left]] == 0 ) {
                freq.erase(num[left]); // Remove element if count is zero
            }
            left++;
        }

        // Update max length
        maxLen = max(maxLen, right - left + 1);
        
        right++; // Move right pointer
    }
    
    return maxLen; // Return the result
}

int main() {
    int num[] = {1, 2, 1, 2, 3, 4, 5, 1, 2}; // Example input
    int n = sizeof(num) / sizeof(num[0]); // Calculate size
    int k = 2; // Max distinct elements allowed
    
    cout << "Longest subarray length: " << findLongestSubarray(n, k, num) << endl;
    
    return 0;
}
