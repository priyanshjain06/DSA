// NOTE  O(m+n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> FindUnion(int arr1[], int arr2[], int n, int m)
{
  int i = 0, j = 0;
  vector<int> Union; // REVIEW -

  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j]) // Case 1 and 2x
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else // case 3
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n) // IF any element left in arr1
  {
    if (Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m) // If any elements left in arr2
  {
    if (Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }
  return Union;
}
