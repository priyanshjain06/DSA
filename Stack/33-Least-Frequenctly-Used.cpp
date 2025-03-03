#include <iostream>
#include <unordered_map>
using namespace std;

class LFUCache
{
public:
    class Node
    {
    public:
        int key;    // The key of the cache entry
        int value;  // The value of the cache entry
        int freq;   // The frequency of access
        Node *next; // Pointer to the next node in the list
        Node *prev; // Pointer to the previous node in the list

        // Constructor to initialize a node with key and value
        Node(int k, int v)
        {
            key = k;
            value = v;
            freq = 1; // When a node is created, it starts with frequency 1
        }
    };

    Node *head = new Node(-1, -1); // Dummy head node (for ease of operations)
    Node *tail = new Node(-1, -1); // Dummy tail node (for ease of operations)

    int capacity;                                           // Maximum capacity of the cache
    unordered_map<int, Node *> keyMap;                      // Maps key to its corresponding node
    unordered_map<int, unordered_map<int, Node *>> freqMap; //REVIEW -  // Maps frequency to a list of nodes with that frequency
    int minFreq;                                            // Tracks the minimum frequency of the cache

    // Constructor to initialize the cache with a given capacity
    LFUCache(int cap)
    {
        capacity = cap;
        minFreq = 0;
        head->next = tail;
        tail->prev = head;
    }

    // Adds a new node to the front of the linked list
    void addNode(Node *newNode)
    {
        Node *temp = head->next; // Get the first node after head
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
    }

    // Removes a node from its current position in the list
    void removeNode(Node *delNode)
    {
        Node *prevNode = delNode->prev;
        Node *nextNode = delNode->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // Updates the frequency of a node after it's accessed
    void updateFrequency(Node *currNode)
    {
        // Remove the node from the current frequency list
        freqMap[currNode->freq].erase(currNode->key);
        if (freqMap[currNode->freq].empty())
        {
            freqMap.erase(currNode->freq); // Remove frequency if no more nodes
            if (minFreq == currNode->freq)
            {
                minFreq++; // Increase minFreq if necessary
            }
        }

        // Increase the frequency of the node
        currNode->freq++;
        freqMap[currNode->freq][currNode->key] = currNode;
    }

    // Retrieves the value of the key from the cache if present
    int get(int key)
    {
        if (keyMap.find(key) == keyMap.end())
        {
            return -1; // Key not found
        }

        Node *node = keyMap[key];
        int value = node->value;

        // Update the frequency and reposition the node
        updateFrequency(node);
        removeNode(node); //REVIEW - 
        addNode(node);

        return value; // Return the value of the key
    }

    // Adds a new key-value pair to the cache or updates an existing one
    void put(int key, int value)
    {
        if (capacity == 0)
            return; // If capacity is 0, do nothing

        // If the key already exists in the cache
        if (keyMap.find(key) != keyMap.end())
        {
            Node *existingNode = keyMap[key];
            existingNode->value = value;
            get(key); // Update frequency and move node to the front
            return;
        }

        // If the cache is full, remove the least frequently used node
        if (keyMap.size() == capacity)
        {
            Node *nodeToRemove = freqMap[minFreq].begin()->second;
            keyMap.erase(nodeToRemove->key);           // Remove from key map
            freqMap[minFreq].erase(nodeToRemove->key); // Remove from frequency map
            removeNode(nodeToRemove);                  // Remove from the linked list
            delete nodeToRemove;                       // Free up memory
        }

        // Create a new node and add it to the cache
        Node *newNode = new Node(key, value);
        addNode(newNode);
        keyMap[key] = newNode;
        freqMap[1][key] = newNode; // New node has frequency 1
        minFreq = 1;               // Reset minFreq to 1 for the new node
    }
};

int main()
{
    LFUCache cache(2);

    cache.put(1, 1);
    cache.put(2, 2);
    cout << "Get 1: " << cache.get(1) << endl; // returns 1
    cache.put(3, 3);                           // evicts key 2
    cout << "Get 2: " << cache.get(2) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 3
    cache.put(4, 4);                           // evicts key 1
    cout << "Get 1: " << cache.get(1) << endl; // returns -1 (not found)
    cout << "Get 3: " << cache.get(3) << endl; // returns 3
    cout << "Get 4: " << cache.get(4) << endl; // returns 4

    return 0;
}
