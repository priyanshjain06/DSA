// NOTE You are given two arrays petrol[] and distance[], where each index i represents a petrol pump:

// petrol[i] represents the amount of petrol available at the i - th petrol pump.distance[i] represents the distance from the i - th petrol pump to the next.Your task is to find the starting petrol pump index from which a truck can start its journey around a circular route and return to the same petrol pump, without the truck running out of petrol.The truck consumes 1 unit of petrol per unit of distance traveled.

// If it's possible to complete the circular route, return the starting petrol pump index. If it’s not possible, return -1.

#include <iostream>
#include <climits>
using namespace std;
class Solution
{
public:
    int tour(int petrol[], int distance[], int n)
    {
        int deficit = 0;
        int balance = 0;
        int start = 0;

        for (int i = 0; i < n; i++)
        {
            balance += petrol[i] - distance[i];
            if (balance < 0)
            {
                start = i + 1; // REVIEW:front = rear + 1
                deficit += balance; //REVIEW - 
                balance = 0;
            }
        }

        if (balance + deficit >= 0)
            return start;
            
        return -1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int petrol[n], distance[n];
        for (int i = 0; i < n; i++)
        {
            cin >> petrol[i] >> distance[i];
        }
        Solution obj;
        cout << obj.tour(petrol, distance, n) << endl;
    }
}
