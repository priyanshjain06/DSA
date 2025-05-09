// NOTE Given an array, print all the elements which are leaders. A Leader is an element that is greater than all of the elements on its right side in the array.

// LINK - time complexity : O(n^2) and space complexity : O(1)

#include <iostream>
#include <vector>

using namespace std;


vector<int> printLeadersBruteForce(int arr[], int n)
{

    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool leader = true;

        // Checking whether arr[i] is greater than all
        // the elements in its right side
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[i])
            {

                // If any element found is greater than current leader
                // curr element is not the leader.
                leader = false;
                break;
            }

        // Push all the leaders in ans array.
        if (leader)
            ans.push_back(arr[i]);
    }

    return ans;
}

int main()
{

    // Array Initialization.
    int n = 6;
    int arr[6] = {10, 22, 12, 3, 0, 6};

    vector<int> ans = printLeadersBruteForce(arr, n);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;
    return 0;
}
