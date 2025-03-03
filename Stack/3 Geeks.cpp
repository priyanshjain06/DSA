//{ Driver Code Starts
#include <iostream>
#include <string>
#include <stack>

using namespace std;

// return the address of the string
char *reverse(char *S, int len)
{
    stack<char> st;

    // Push all characters onto the stack
    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }

    // Pop characters from stack and overwrite the string
    for (int i = 0; i < len; i++)
    {
        S[i] = st.top();
        st.pop();
    }

    return S; // Return the reversed string
}