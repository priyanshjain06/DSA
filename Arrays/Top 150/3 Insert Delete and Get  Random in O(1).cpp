class RandomizedSet
{
public:
    vector<int> vals;
    unordered_map<int, int> valToIndex; // REVIEW -  to store the index of the array elements

    bool insert(int val)
    {
        if (valToIndex.count(val))
            return false;
        valToIndex[val] = vals.size(); //REVIEW 
        vals.push_back(val);
        return true;
    }

    bool remove(int val) //REVIEW - 
    {
        if (!valToIndex.count(val))
            return false;

        int idx = valToIndex[val];
        int last = vals.back();

        vals[idx] = last;
        valToIndex[last] = idx;
        
        vals.pop_back();
        valToIndex.erase(val);
        return true;
    }

    int getRandom()
    {
        return vals[rand() % vals.size()];
        // REVIEW -  rand () works in O(1)
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */