// NOTE we need to calculate the maximum cosecutive number of days for which price  of stock is less than or equal to current day's price

// ANCHOR -  Time Complexity: O(N ^ 2) and Space Complexity: O(N)

#include <iostream>
#include <vector>

using namespace std;

void calculateSpan(int price[], int n, int S[])
{
    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        S[i] = 1;

        for (int j = i - 1;
             (j >= 0) && (price[i] >= price[j]); j--)
            S[i]++;
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int main()
{
    int price[] = {10, 4, 5, 90, 120, 80};
    int n = price.size();
    int S[n];

    calculateSpan(price, n, S);

    printArray(S, n);

    return 0;
}
