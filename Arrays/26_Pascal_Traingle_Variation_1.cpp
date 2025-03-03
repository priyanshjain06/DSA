//NOTE -  Pascal Triangle : Variation 1:
// Variation 1: Given row number r and column number c. Print the element at position (r, c) in Pascal’s triangle.

//ANCHOR -  for brute force see the screenshot 

//LINK -   time complexity O(c) => c is column and space complexity is O(1)

#include <iostream>

using namespace std;

int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c)
{
    int element = nCr(r - 1, c - 1); //REVIEW - 
    return element;
}


int main()
{
    int r = 5; // row number
    int c = 3; // col number
    int element = pascalTriangle(r, c);
    cout << "The element at position (r,c) is: "
         << element << "n";
    return 0;
}
