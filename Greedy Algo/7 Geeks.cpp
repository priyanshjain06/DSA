//{ Driver Code Starts
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;
// } Driver Code Ends
class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<pair<int, int>> meetings; //REVIEW 
        
        for (int i = 0; i < n; i++) {
            meetings.push_back({end[i], start[i]}); //REVIEW 
        }
        
        sort(meetings.begin(), meetings.end());
        
        int count = 1;
        int last_end = meetings[0].first;
        
        for (int i = 1; i < n; i++) { //REVIEW -  1 start not 0
            if (meetings[i].second > last_end) {
                count++; //REVIEW - 
                last_end = meetings[i].first;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> start;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            start.push_back(num);
        }

        vector<int> end;
        getline(cin, input);
        stringstream s22(input);
        while (s22 >> num) {
            end.push_back(num);
        }

        Solution ob;
        int ans = ob.maxMeetings(start, end);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
