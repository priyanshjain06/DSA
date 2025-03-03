#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int minimumCost(vector<int> arr) {
    priority_queue<int, vector<int>, greater<int> > minHeap; //REVIEW - 
    int cost = 0;

    for(auto i : arr) {
        minHeap.push(i); // insert all values in minheap // REVIEW -
    }

    while(minHeap.size() > 1) {
        int a = minHeap.top();
        minHeap.pop();

        int b = minHeap.top();
        minHeap.pop();

        int sum = a + b;
        cost += sum; //REVIEW - 
        minHeap.push(sum); //REVIEW - 
    }

    return cost;
}

int main() {
    vector<int> arr;

    cout << "Enter the elements of array (-1 to stop) : ";
    int temp;
    cin >> temp;
    while(temp != -1) {
        arr.push_back(temp);
        cin >> temp;
    }

    int cost = minimumCost(arr);

    cout << "Minimum cost to join all ropes = " << cost << endl;

    return 0;
}