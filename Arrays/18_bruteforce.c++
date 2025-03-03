// NOTE - There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

#include <iostream>
#include <vector>
using namespace std;

vector<int> RearrangebySign(vector<int> A, int n)
{

  // Define 2 vectors, one for storing positive
  // and other for negative elements of the array.
  vector<int> pos;
  vector<int> neg;

  // Segregate the array into positives and negatives.
  for (int i = 0; i < n; i++)
  {

    if (A[i] > 0)
      pos.push_back(A[i]);
    else
      neg.push_back(A[i]);
  }

  // Positives on even indices, negatives on odd.
  for (int i = 0; i < n / 2; i++)
  {

    A[2 * i] = pos[i];
    A[2 * i + 1] = neg[i];
  }

  return A;
}

int main()
{

  // Array Initialisation.
  int n = 4;
  vector<int> A{1, 2, -4, -5};

  vector<int> ans = RearrangebySign(A, n);

  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }

  return 0;
}