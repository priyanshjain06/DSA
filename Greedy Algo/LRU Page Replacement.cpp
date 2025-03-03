#include <iostream> 
#include <unordered_set>
#include <list>
using namespace std;

class Solution
{
public:
    int pageFaults(int N, int C, int pages[])
    {
        unordered_set<int> pageSet; // Set to check if page is in memory
        list<int> pageList;         // List to maintain order of pages
        int pageFaultCount = 0;

        for (int i = 0; i < N; i++)
        {
            int currentPage = pages[i];

            // If the page is not in memory, it's a page fault
            if (pageSet.find(currentPage) == pageSet.end())
            {
                pageFaultCount++;

                // If memory is full, remove the least recently used page
                if (pageSet.size() == C)
                {
                    int lruPage = pageList.back(); // Get the least recently used page
                    pageSet.erase(lruPage);        // Remove from set
                    pageList.pop_back();           // Remove from list
                }

                // Add the new page to memory
                pageSet.insert(currentPage);
                pageList.push_front(currentPage); // Move the page to the front
            }
            else
            {
                // If the page is already in memory, just move it to the front
                pageList.remove(currentPage);     // Remove the page
                pageList.push_front(currentPage); // Add it to the front
            }
        }

        return pageFaultCount;
    }
};

