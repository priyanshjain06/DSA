// NOTE we need to calculate the maximum cosecutive number of days for which price  of stock is less than or equal to current day's price

// ANCHOR -  Time Complexity: O(N) and Space Complexity: O(N)

#include <iostream>
#include <stack>
using namespace std;
void calculateSpan(int price[], int n, int S[])
{
    stack<int> st;
    st.push(0); // REVIEW -

    S[0] = 1;

    for (int i = 1; i < n; i++)
    {
        while (!st.empty() && price[st.top()] <= price[i])
            st.pop();

        S[i] = (st.empty()) ? (i + 1) : (i - st.top()); // i+1 =>0+1

        st.push(i);
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
    calculateSpan(price, n, S);
    printArray(S, n);
    return 0;
}
