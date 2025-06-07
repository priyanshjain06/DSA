#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Comparator for Min Heap
struct Compare //REVIEW - 
{
    bool operator()(ListNode *a, ListNode *b)
    {
        return a->val > b->val; // Min heap based on value
    }
};

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<ListNode *, vector<ListNode *>, Compare> minHeap;

    // Push the head of each list into the heap
    for (auto list : lists)
    {
        if (list)
            minHeap.push(list);
    }

    ListNode *dummy = new ListNode(0);
    ListNode *tail = dummy;

    // Extract min node and move to next
    while (!minHeap.empty())
    {
        ListNode *smallest = minHeap.top();
        minHeap.pop();
        tail->next = smallest;
        tail = tail->next;

        if (smallest->next)
            minHeap.push(smallest->next);
    }

    return dummy->next; 
}
