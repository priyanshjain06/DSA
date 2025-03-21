// NOTE we need to calculate the maximum cosecutive number of days for which price  of stock is less than or equal to current day's price

// ANCHOR -  Time Complexity: O(N) and Space Complexity: O(N)

#include <stack>
using namespace std;

class StockSpanner
{
public:
    stack<pair<int, int>> st; // Stores (price, span)

    StockSpanner() {} // REVIEW  Read the question also the example

    int next(int price) // REVIEW
    {
        int span = 1;

        // Pop smaller prices and accumulate their spans
        while (!st.empty() && st.top().first <= price)
        {
            span += st.top().second;
            st.pop();
        }

        // Push the current price and its computed span
        st.push({price, span});
        return span;
    }
};
