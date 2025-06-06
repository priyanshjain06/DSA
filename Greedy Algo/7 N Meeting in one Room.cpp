#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct meeting
{
   int start;
   int end;
   int pos;
};

class Solution
{
public:
   static bool comparator(struct meeting m1, struct meeting m2) // REVIEW structure type
   {
      if (m1.end != m2.end)
         return m1.end < m2.end; // REVIEW
      return m1.pos < m2.pos;    // REVIEW If end times are equal, sort by position
   }

   void maxMeetings(int s[], int e[], int n)
   {
      struct meeting meet[n]; // REVIEW structure type

      for (int i = 0; i < n; i++)
      {
         meet[i].start = s[i], meet[i].end = e[i], meet[i].pos = i + 1;
         // REVIEW i+1 for position !
      }

      sort(meet, meet + n, comparator); // FIXME -

      vector<int> answer;

      int limit = meet[0].end;
      answer.push_back(meet[0].pos);

      for (int i = 1; i < n; i++)
      {
         if (meet[i].start > limit)
         {
            //  count++ //REVIEW count of the meetings !
            limit = meet[i].end;
            answer.push_back(meet[i].pos);
         }
      }
      cout << "The order in which the meetings will be performed is " << endl;
      for (int i = 0; i < answer.size(); i++)
      {
         cout << answer[i] << " ";
      }
   }
};
int main()
{
   Solution obj;
   int n = 6;
   int start[] = {1, 3, 0, 5, 8, 5};
   int end[] = {2, 4, 5, 7, 9, 9};
   obj.maxMeetings(start, end, n);
   return 0;
}