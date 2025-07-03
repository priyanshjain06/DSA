#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        vector<pair<int, int>> result; // REVIEW - pair of vector !
        if (!head)
            return result; // Edge case

        // Finding the tail of DLL
        Node *left = head, *right = head;

        while (right->next) 
            right = right->next; 

        // Two-pointer approach
        while (left != right && left->prev != right) // REVIEW -
        {
            int sum = left->data + right->data;
            if (sum == target)
            {
                result.push_back({left->data, right->data}); // REVIEW
                left = left->next;
                right = right->prev;
            }
            else if (sum < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }

        return result;
    }
};
