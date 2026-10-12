class RandomizedSet {
public:
    unordered_map<int, int> pos;
    vector<int> arr;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        auto it = pos.find(val);
        if(it != pos.end()) return false;
        arr.push_back(val);
        pos[val] = arr.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        auto it = pos.find(val);
        if(it == pos.end()) return false;
        pos[arr.back()] = it->second;
        swap(arr.back(), arr[it->second]);
        pos.erase(val);
        arr.pop_back();
        return true;
    }
    
    int getRandom() {
        return arr[rand() % arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */