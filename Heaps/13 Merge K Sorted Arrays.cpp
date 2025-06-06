//{ Driver Code Starts
#include <iostream>
#include <vector>
#include <queue>
#define N 105
using namespace std;

void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}
// } Driver Code Ends

// User function Template for C++
class Node
{
public:
    int data, row, col;

    Node(int val, int r, int c)
    {
        data = val;
        row = r;
        col = c;
    }
};

class compare
{
public:
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data; // Min heap
    }
};

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        priority_queue<Node *, vector<Node *>, compare> minHeap; // FIXME
        vector<int> ans;

        // Step 1: Insert first elements from each row into the heap
        for (int i = 0; i < K; i++)
        {
            Node *temp = new Node(arr[i][0], i, 0); // value row col
            minHeap.push(temp);
        }

        // Step 2: Process heap elements
        while (!minHeap.empty())
        {
            Node *temp = minHeap.top();
            minHeap.pop();
            ans.push_back(temp->data);

            int row = temp->row, col = temp->col;

            // If next element exists in the same row, push it to the heap
            if (col + 1 < arr[row].size())
            {
                Node *next = new Node(arr[row][col + 1], row, col + 1); // REVIEW
                minHeap.push(next);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int k;
        cin >> k;
        vector<vector<int>> arr(k, vector<int>(k, 0));

        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < k; j++)
            {
                cin >> arr[i][j];
            }
        }

        Solution obj;
        vector<int> output = obj.mergeKArrays(arr, k);
        printArray(output, k * k);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
