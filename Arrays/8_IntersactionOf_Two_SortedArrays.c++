// NOTE -  time complexity is O(n)

// ANCHOR Given two integer arrays nums1 and nums2, return an array of their
//  intersection
//  . Each element in the result must be unique and you may return the result in any order.
//  Example 1:
// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.


#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectionOfArrays(vector<int> A, vector<int> B)
{

  // Declare ans array.
  vector<int> ans;

  int i = 0, j = 0;

  // to traverse the arraysz
  while (i < A.size() && j < B.size())
  {

    // if current element in i is smaller
    if (A[i] < B[j])
    {
      i++;
    }
    else if (B[j] < A[i])
    {
      j++;
    }
    else
    {
      // both elements are equal
      ans.push_back(A[i]);
      i++;
      j++;
    }
  }
  return ans;
}
