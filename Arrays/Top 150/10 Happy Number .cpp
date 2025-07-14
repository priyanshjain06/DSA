// REVIEW Use fast and slow pointers
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    int getNext(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n, fast = getNext(n);
        while (fast != 1 && slow != fast)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1; //REVIEW 
    }
};

// REVIEW Another method use set to store the  previous calucated answer to find the loop :

bool isHappy(int n)
{
    unordered_set<int> seen;
    while (n != 1 && !seen.count(n))
    {
        seen.insert(n);
         n = getNext(n);
    }
    return n == 1;
}
