#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class Solution 
{
public:
    int checkCompressed(string S, string T)
    {
        int i = 0, j = 0;

        while (j < T.size())
        {
            if (isdigit(T[j]))
            {
                int num = 0;

                while (j < T.size() && isdigit(T[j]))
                {
                    num = num * 10 + (T[j] - '0');
                    j++;
                }

                i += num;
            }
            else
            {
                if(i >= S.size() || S[i] != T[j])
                    return 0;
                i++,  j++;
            }
        }

        return i == S.size() ? 1 : 0;
    }
};