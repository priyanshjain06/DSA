// class Solution {
// public:
//     // Function to sort jobs by profit in descending order
//     static bool compareProfit(int job1, int job2, const vector<int>& profit) { 
//         return profit[job1] > profit[job2];  // Sort by profit in descending order
//     }

//     // Function to perform job scheduling and return the total number of jobs done and total profit
//     vector<int> JobSequencing(vector<int>& jobIds, vector<int>& deadlines, vector<int>& profits) {
//         int n = jobIds.size();  // Number of jobs
        
//         // Create a vector of job indices to sort the jobs by profit
//         vector<int> jobIndices(n);
//         for (int i = 0; i < n; i++) {
//             jobIndices[i] = i;  // Assign each job an index (0 to n-1)
//         }

//         // Sort the jobs in descending order of profit using the job indices
//         sort(jobIndices.begin(), jobIndices.end(), [&](int job1, int job2) {
//             return compareProfit(job1, job2, profits);
//         });

//         // Find the maximum deadline to know how many slots we need
//     //NOTE *    int maxi = *max_element(deadlines.begin(), deadlines.end());

//         // Slot vector to track scheduled jobs; -1 means the slot is free
//         vector<int> slot(maxi + 1, -1);  // Initializing with -1 (empty slots)

//         int jobsDone = 0;  // To keep track of the number of jobs done
//         int totalProfit = 0;  // To keep track of the total profit earned

//         // Iterate through each job in order of highest profit
//         for (int i = 0; i < n; i++) {
//             // Try to find a free slot for the current job
//             for (int j = deadlines[jobIndices[i]]; j > 0; j--) {
//                 if (slot[j] == -1) {  // If the slot is empty
//                     slot[j] = jobIndices[i];  // Assign the job to this slot
//                     jobsDone++;  // Increment the number of jobs done
//                     totalProfit += profits[jobIndices[i]];  // Add profit for the job
//                     break;  // Stop searching for a slot for this job
//                 }
//             }
//         }

//         // Return a vector with two values: the number of jobs done and the total profit
//         return {jobsDone, totalProfit}; // The first value is jobs done, the second is total profit
//     }
// };