class Solution {
public:
    const int MOD = 1e9 + 7; //REVIEW - 

    // Function to calculate base^exp % mod using Exponentiation by Squaring
    long long modPow(long long base, long long exp, int mod) {
        long long result = 1;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            base = (base * base) % mod;
            exp /= 2;
        }
        return result;
    }

    int countGoodNumbers(long long n) { //REVIEW here n is the length
        // Even positions are (n+1)/2 and Odd positions are n/2
        long long evenPositions = (n + 1) / 2;  // Positions with even indices (0, 2, 4, ...)
        long long oddPositions = n / 2;         // Positions with odd indices (1, 3, 5, ...)
        
        // The number of valid choices for even positions (0, 2, 4, 6, 8)
        long long evenChoices = modPow(5, evenPositions, MOD); // 5 choices for even positions //REVIEW - 
        // The number of valid choices for odd positions (2, 3, 5, 7)
        long long oddChoices = modPow(4, oddPositions, MOD);  // 4 choices for odd positions
        
        // Total good numbers is the product of choices for even and odd positions
        return (evenChoices * oddChoices) % MOD;
    }
};