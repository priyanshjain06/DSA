//NOTE reove duplicate elements from array

// BRute force : see sreeenshot using sorted set

// optimal 

#include <iostream>
#include <vector>
using namespace std ;
int removeDuplicate(int n , vector<int> &arr)
{
    int i = 0;
    for (int j=1 ;j<=n-1;j++)
    {
        if(arr[i]!= arr[j])
        {
            arr[i]= arr[j];
            i++;
        }
    }
    return i+1; //REVIEW - 
}
