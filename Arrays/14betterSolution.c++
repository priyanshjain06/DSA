// NOTE -

// LINK -  we use undordered map where we are trying to find target -num (complemet of the number in the undordered map) for every particular number in the hash .

//LINK -  the alogo =>

// For index 0, x = 2, and currently map is empty.
// We try to find if target – x = 4 – 2 = 2 is present in the map or not.
// For now, 2 does not exist on the map.
// And we store the index of element 2. i.e., mp[2] = 0,

// For index 1, x = 3
// We try to find if target – x = 4  – 3 = 1 is present in the map or not.
// For now, 1 does not exist on the map.
// And we store the index of element 3. i.e., mp[3] = 1,

// For index 2, x = 1 
// We try to find if target – i = 4  – 1 = 3 is present in the map or not. 3 exists in the map, so we store index 2 and the value stored for key 3 in the map and break the loop. And return [1,2].

#include <iostream>
#include <vector>
#include <unordered_map> //NOTE

using namespace std;

vector<int> twoSum(int n, vector<int> &arr, int target) {
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        int num = arr[i];
        int moreNeeded = target - num;
        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return { -1, -1};
}

int main()
{
    int n = 5;
    vector<int> arr = {2, 6, 5, 8, 11};
    int target = 14;
    vector<int> ans = twoSum(n, arr, target);
    cout << "This is the answer for variant 2: [" << ans[0] << ", "
         << ans[1] << "]" << endl;
    return 0;
}