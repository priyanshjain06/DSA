class Solution {
    public:
      double myPow(double x, int n) {
        // Base case: x^0 = 1
        if (n == 0) return 1.0;
        
        // Convert negative exponent to positive safely
        long long N = n;  // Use long long to avoid overflow
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
    
        double result = 1.0;
        while (N > 0) {
            if (N % 2 == 1) { // If odd, multiply x once
                result *= x;
            }
            x *= x;  // Square x
            N /= 2;  // Reduce exponent
        }
    
        return result;
    }
    };