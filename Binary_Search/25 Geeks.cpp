//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
public:
    long long minTime(vector<int>& arr, int k) {
        int n = arr.size();
        if (n < k) return -1; 

        long long low = *max_element(arr.begin(), arr.end()); 
        long long high = accumulate(arr.begin(), arr.end(), 0LL); 
        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (canPaint(arr, n, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }

private:
    bool canPaint(vector<int>& arr, int n, int k, long long maxTime) {
        int painters = 1;
        long long currentTime = 0;
        for (int i = 0; i < n; ++i) {
            currentTime += arr[i];
            if (currentTime > maxTime) {
                ++painters;
                currentTime = arr[i];
                if (painters > k) {
                    return false;
                }
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution obj;
        cout << obj.minTime(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends