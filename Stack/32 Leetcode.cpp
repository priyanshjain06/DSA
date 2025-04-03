#include <iostream>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache;

    // Stores {key, value} with most recently used at the front
    unordered_map<int, list<pair<int, int>>::iterator> map;
    // REVIEW   Key(position of list) -> Iterator to list node

public:
    LRUCache(int cap)
    {
        capacity = cap;
    }

    int get(int key)
    {
        if (map.find(key) == map.end())
        {
            return -1; // Key not found
        }

        // Move the accessed node to the front (most recently used)
        cache.splice(cache.begin(), cache, map[key]);
        // REVIEW list_name.splice(destination, source, iterator);
        // REVIEW to move the recently used to front !

        // FIXME -
        return map[key]->second; // Return value
    }

    void put(int key, int value)
    {
        if (map.find(key) != map.end())
        {
            // If key exists, move to front and update value
            cache.splice(cache.begin(), cache, map[key]);
            map[key]->second = value;
            return;
        }

        if (cache.size() == capacity)
        {
            // Remove the least recently used (back of list)
            int lruKey = cache.back().first;
            map.erase(lruKey);
            cache.pop_back();
        }

        // Insert new item at the front
        cache.push_front({key, value});
        map[key] = cache.begin();
    }
};
