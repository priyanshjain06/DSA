// User function template for C++
class Solution
{
public:
    long long int findBitwiseOR(long long int L, long long int R)
    {
        // complete the function here

        // Find the common left-most bits

        while ((L | 1) < R)
        {
            L |= (L + 1);
        }
        return L | R;
    }
};

//REVIEW Logic :
// OR accumulates all 1s that occur in any position across the range.

// If any bit changes between left and right, all bits after that position will eventually become 1 due to OR.

// So we try to propagate 1s across changing bits efficiently.