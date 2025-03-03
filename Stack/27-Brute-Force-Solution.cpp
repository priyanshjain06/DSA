//NOTE : arr = [3, 5, 2, 7, 5, 8, 6]
// Queries: Q = [0, 2, 3]

//For index 0 (i.e., arr[0] = 3): =====>
// Look at the elements to the right: [5, 2, 7, 5, 8, 6].
// Elements greater than 3 are: [5, 7, 5, 8, 6].
// Count of elements greater than 3 is 5.

#include <iostream>
#include <vector>
using namespace std;
int nextGreaterElements(vector<int> &a, int index)
{
    int count = 0, N = a.size();
    for (int i = index + 1; i < N; i++)
        if (a[i] > a[index])
            count++;

    return count;
}

int main()
{

    vector<int> a = {3, 4, 2, 7, 5, 8, 10, 6};
    int Q = 2;
    vector<int> queries = {0, 5};

    for (int i = 0; i < Q; i++)
        // Function call
        cout << nextGreaterElements(a, queries[i]) << " ";

    return 0;
}
