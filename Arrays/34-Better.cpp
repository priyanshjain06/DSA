// NOTE -  You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// ANCHOR - Time Complexity: O(2N)  and Space Complexity : O(n)

#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    vector<int> hashArray(n + 1, 0); // REVIEW - n+1  and dont use the syntax as hashArray[n+1] ={0}

    for (int i = 0; i < n; i++)
    {
        hashArray[a[i]]++;
    }

    // Find the repeating and missing numbers:
    int repeating = -1, missing = -1;
    for (int i = 1; i <= n; i++)
    {
        if (hashArray[i] == 2)
            repeating = i;
        else if (hashArray[i] == 0)
            missing = i;

        if (repeating != -1 && missing != -1)
            break;
    }
    return {repeating, missing};
}

int main()
{
    vector<int> a = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepeatingNumbers(a);
    cout << "The repeating and missing numbers are: {"
         << ans[0] << ", " << ans[1] << "}\n";
    return 0;
}
