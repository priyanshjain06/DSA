#include <vector>
#include <iostream>
using namespace std;

vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        int nextSmaller = -1;
        // Default to -1 if no smaller element is found
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[i])
            {
                nextSmaller = arr[j]; // Found the next smaller element
                break;                // Stop once we've found the first smaller element
            }
        }
        ans[i] = nextSmaller; // Store the result for current element
    }

    return ans;
}

int main()
{
    vector<int> arr = {4, 8, 5, 2, 25};
    int n = arr.size();

    vector<int> result = nextSmallerElement(arr, n);

    cout << "Next smaller elements are: ";
    for (int i = 0; i < n; i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}
