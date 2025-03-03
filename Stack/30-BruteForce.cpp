#include <iostream>
using namespace std;

string buildLowestNumber(string str, int n)
{
    // Base Case 1: If n == 0, append the whole 'str' to 'res' and return
    if (n == 0)
    {
        return str;
    }

    int len = str.size();

    // Base Case 2: If 'len' is smaller or equal to n, everything can be removed
    if (len <= n)
    {
        return "";
    }

    // Find the smallest character among the first (n+1) characters of 'str'
    int minIndex = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (str[i] < str[minIndex])
        {
            minIndex = i;
        }
    }

    // Append 'str[minIndex]' to 'res' and recur for the substring after minIndex
    // and for n = n-minIndex
    return str[minIndex] + buildLowestNumber(str.substr(minIndex + 1), n - minIndex);
}

int main()
{
    string str = "765028321";
    int k = 5;

    string result = buildLowestNumber(str, k);

    // Output the result
    if (result.empty())
    {
        cout << "0\n";
    }
    else
    {
        cout << result << "\n";
    }

    return 0;
}
