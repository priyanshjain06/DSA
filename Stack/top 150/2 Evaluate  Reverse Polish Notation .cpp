class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> st;

        for (const string &token : tokens) // REVIEW
        {
            if (token == "+" || token == "-" || token == "*" || token == "/")
            {
                // REVIEW first b then a
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b); // REVIEW Integer division, truncate toward zero
            }
            else
            {
                st.push(stoi(token)); // FIXME  // REVIEW  Convert string to integer
            }
        }

        return st.top(); // REVIEW  Final result
    }
};
