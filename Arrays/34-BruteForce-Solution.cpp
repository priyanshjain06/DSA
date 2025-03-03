// NOTE -  You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// ANCHOR - Time Complexity: O(N^2)  and Space Complexity : O(1)


#include <iostream>
#include <vector>
using namespace std;

vector<int> findMissingRepeatingNumbers(vector<int> a)
{
    int n = a.size();
    int repeating = -1, missing = -1;

    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] == i)
                cnt++;
        }

        if (cnt == 2)
            repeating = i;
        else if (cnt == 0)
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
