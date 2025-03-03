#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    long long countGraphs(int n)
    {
        return pow(2, (n * (n - 1)) / 2);//REVIEW -  n-1
    }
};

int main()
{
    int n;
    cin >> n;
    Solution obj;
    cout << obj.countGraphs(n) << endl;
    return 0;
}
