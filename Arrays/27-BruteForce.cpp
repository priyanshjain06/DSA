
// ANCHOR -  Time Complexity: O(N2) and Space Complexity: O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> majorityElement(vector<int> v)
{
    int n = v.size(); // size of the array
    vector<int> ls;   // list of answers

    for (int i = 0; i < n; i++)
    {
        // selected element is v[i]:
        //  Checking if v[i] is not already
        //  a part of the answer:
        if (ls.size() == 0 || ls[0] != v[i]) //REVIEW - 
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                // counting the frequency of v[i]
                if (v[j] == v[i])
                {
                    cnt++;
                }
            }

            // check if frquency is greater than n/3:
            if (cnt > (n / 3))
                ls.push_back(v[i]);
        }

        if (ls.size() == 2) //REVIEW - 
            break;
    }

    return ls;
}

int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}
