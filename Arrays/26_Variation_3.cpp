// NOTE Variation 3: Given the number of rows n. Print the first n rows of Pascal’s triangle.

// ANCHOR -  for brute force see screenshot

// LINK -  time complexity O(n^2) => n is number of rows and space complexity is O(1)

#include <iostream>
#include <vector>
using namespace std;

vector<int> generateRow(int row)
{
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); // inserting the 1st element //REVIEW - 

    // calculate the rest of the elements:
    for (int col = 1; col <= row-1; col++) //REVIEW - 
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans); //REVIEW - 
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) 
{
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) //REVIEW - 
    {
        ans.push_back(generateRow(row)); //REVIEW - 
    }
    return ans;
}

int main()
{
    int n = 5;
    vector<vector<int>> ans = pascalTriangle(n);
    for (auto it : ans)
    {
        for (auto ele : it)
        {
            cout << ele << " ";
        }
        cout << "n";
    }
    return 0;
}
