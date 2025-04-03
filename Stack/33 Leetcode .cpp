#include <unordered_map>
#include <list>
#include <iostream>

using namespace std;

class LFUCache
{
private:
    int capacity, minFreq;
    unordered_map<int, int> keyValue;                    // Stores {key → value}
    unordered_map<int, int> keyFreq;                     // Stores {key → frequency}
    unordered_map<int, list<int>> freqKeys;              // Stores {frequency → list of keys}
    unordered_map<int, list<int>::iterator> keyIterator; // {key → iterator in list}

public:
    LFUCache(int cap)
    {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key)
    {
        if (keyValue.find(key) == keyValue.end())
        {
            return -1; // Key not found
        }

        increaseFrequency(key);
        return keyValue[key];
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        if (keyValue.find(key) != keyValue.end())
        {
            keyValue[key] = value;
            increaseFrequency(key);
            return;
        }

        if (keyValue.size() == capacity)
        {
            removeLFU();
        }

        // Insert new key-value pair
        keyValue[key] = value;
        keyFreq[key] = 1;
        freqKeys[1].push_back(key);
        keyIterator[key] = --freqKeys[1].end();
        minFreq = 1;
    }

private:
    void increaseFrequency(int key)
    {
        int freq = keyFreq[key];
        freqKeys[freq].erase(keyIterator[key]);

        if (freqKeys[freq].empty() && freq == minFreq)
        {
            minFreq++;
        }

        keyFreq[key] = freq + 1;
        freqKeys[freq + 1].push_back(key);
        keyIterator[key] = --freqKeys[freq + 1].end();
    }

    void removeLFU()
    {
        int lfuKey = freqKeys[minFreq].front();
        freqKeys[minFreq].pop_front();

        keyValue.erase(lfuKey);
        keyFreq.erase(lfuKey);
        keyIterator.erase(lfuKey);
    }
};
