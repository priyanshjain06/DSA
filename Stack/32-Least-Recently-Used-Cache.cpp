// ANCHOR  Time Complexity : O(N) and Space Complexity : O(1)

#include <iostream>
#include <unordered_map>
using namespace std;
class LRUCache
{
public:
    class node //REVIEW class within a class 
    {
    public:
        int key;
        int val;
        node *next;
        node *prev;
        node(int _key, int _val) // REVIEW -
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1); // REVIEW -
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> m; // REVIEW -

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {
        if (m.find(key_) != m.end())
        {
            node *resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }

        return -1;
    }

    void put(int key_, int value) // REVIEW -  it is value not _value
    {
        if (m.find(key_) != m.end())
        {
            node *existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key); //REVIEW - 
            deletenode(tail->prev); //REVIEW - 
        } 

        addnode(new node(key_, value));
        m[key_] = head->next;
    }
};