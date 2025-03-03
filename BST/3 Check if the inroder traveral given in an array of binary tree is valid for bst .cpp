// // User function Template for C++
// class Solution {
//   public:
//     bool isBSTTraversal(vector<int>& arr) {
//         // Traverse the array and check if it is sorted in strictly increasing order
//         for (int i = 1; i < arr.size(); i++) { //NOTE
//             if (arr[i] <= arr[i - 1]) {
//                 return false; // Not strictly increasing
//             }
//         }
//         return true; // All elements are strictly increasing
//     }
// };
