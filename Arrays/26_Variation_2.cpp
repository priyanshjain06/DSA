// NOTE -  Variation 2: Given the row number n. Print the n-th row of Pascal’s triangle.

// ANCHOR -  for brute force check screenshot

// LINK - time compexity is 0(r) where r is row and space complexity is 0(1)

#include <iostream>

using namespace std;

void pascalTriangle(int n)
{
    long long ans = 1;
    cout << ans << " "; // printing 1st element

    // Printing the rest of the part:
    for (int i = 1; i < n; i++) //REVIEW - 
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

int main()
{
    int n = 5;
    pascalTriangle(n);
    return 0;
}
