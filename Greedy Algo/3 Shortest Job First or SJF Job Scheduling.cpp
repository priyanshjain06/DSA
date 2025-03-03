              
#include <vector>   
#include <algorithm>
#include <iostream>
//NOTE 
// ## Approach:
// 1. **Greedy Approach**: We can use a greedy approach to solve this problem. The idea is to keep track of the farthest index we can reach at any point.
// 2. At each index, check if it is possible to jump further. If the current index is beyond the farthest index we can reach, return `false` because it means we cannot reach this index.
// 3. If we can update the farthest index at each position, and eventually the farthest index reaches or exceeds the last index, return `true`.
using namespace std;

// Function to calculate average
// waiting time using Shortest
// Job First algorithm
float shortestJobFirst(vector<int> jobs) {
    // Sort the jobs in ascending order
    sort(jobs.begin(), jobs.end()); 

    // Initialize total waiting time
    float waitTime = 0; 
    // Initialize total time taken
    int totalTime = 0; 
    // Get the number of jobs
    int n = jobs.size(); 

    // Iterate through each job
    // to calculate waiting time
    for(int i = 0; i < n; ++i) {
        
        // Add current total
        // time to waiting time
        waitTime += totalTime;  //REVIEW - 
        // Add current job's
        // time to total time
        totalTime += jobs[i]; 
    }
    
    // Return the average waiting time
    return waitTime / n;  
}

int main() {
    vector<int> jobs = {4, 3, 7, 1, 2};
    
    cout << "Array Representing Job Durations: ";
    for(int i = 0; i < jobs.size(); i++){
        cout << jobs[i] << " ";
    }
    cout << endl;
    
    float ans = shortestJobFirst(jobs);
    cout << "Average waiting time: "<< ans;
    cout << endl;

    return 0;
}
                            
                        