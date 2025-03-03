// ANCHOR -Time Complexity: O(N^2 * log(no. of unique triplets)), Space Complexity: O(2 * no. of the unique triplets)

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int>> triplet(int n, vector<int> &arr)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset; //REVIEW -  SO that hash gets reset each time
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end()) //REVIEW - 
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end()); //REVIEW - 
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans)
    {
        cout << "[";
        for (auto i : it)
        {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}
