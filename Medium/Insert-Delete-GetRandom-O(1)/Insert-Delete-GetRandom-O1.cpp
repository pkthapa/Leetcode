#include "main.hpp"

// https://www.youtube.com/watch?v=j4KwhBziOpg&ab_channel=NeetCode

class RandomizedSet {
    // 'arr' stores the inserted value.
    // 'mp' stores the inserted value and its inserted-index in 'arr'.
    // Use 'rand()' to generate random number.
    
    // <val, index-of-arr>
    unordered_map<int, int> mp;
    vector<int> arr; // To get random value in O(1).
    
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.find(val) != mp.end()) {
            return false;
        }
        
        arr.emplace_back(val);
        mp[val] = arr.size() - 1;

        return true;
    }
    
    // Delete the 'val' by replacing it with the last index value from 'arr' array
    // and update the index to 'mp'.
    bool remove(int val) {
        if (mp.find(val) == mp.end()) {
            return false;
        }
        
        int last = arr.back();
        
        // Update 'mp'.
        mp[last] = mp[val];
        
        // Update 'arr'.
        arr[mp[val]] = last;

        // Deletion of 'val' entries.
        arr.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

int main() {
    RandomizedSet* obj = new RandomizedSet();

    assert(true == obj->insert(1));
    assert(false == obj->remove(2));
    assert(true == obj->insert(2));
    auto ret = obj->getRandom();
    assert(1 == ret || 2 == ret);
    assert(true == obj->remove(1));
    assert(false == obj->insert(2));
    assert(2 == obj->getRandom());

    delete obj;
    
    return 0;
}