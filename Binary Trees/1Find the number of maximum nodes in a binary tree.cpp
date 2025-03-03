// REVIEW  Time Complexity: O(1)
// REVIEW  Space Complexity: O(1)

#include <iostream>
#include <math.h>
using namespace std;
class Solution
{
public:
    int countNodes(int i)
    {
        return pow(2, i - 1); //REVIEW 
    }
};
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int i;
        cin >> i;
        Solution ob;
        int res = ob.countNodes(i);
        cout << res << "\n";
        cout << "~" << "\n";
    }
}