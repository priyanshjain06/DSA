// NOTE Problem Statement: You have been given a non-empty grid ‘mat’ with 'n' rows and 'm' columns consisting of only 0s and 1s. All the rows are sorted in ascending order.
//  Your task is to find the index of the row with the maximum number of ones.
//SECTION  Note: If two rows have the same number of ones, consider the one with a smaller index. If there's no row with at least 1 zero, return -1.

// REVIEW - Time Complexity: O(n * log(m)) and Space Complexity : O(1)

#include <iostream>
#include <vector>
using namespace std;
int lowerBound(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1; //REVIEW -  high = n , n= row
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0;
    int index = -1;

    // traverse the rows:
    for (int i = 0; i < n; i++) 
    {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1); // REVIEW - m=>col
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
}
