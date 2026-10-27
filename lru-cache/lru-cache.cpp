class LRUCache {
public:
    using ll = int;
    list<pair<int, int>> ls;
    unordered_map<int, list<pair<int, int>> :: iterator> mp;
    int m_capacity;
    LRUCache(int capacity) : m_capacity{capacity}{
        
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end())  return -1;
        ll val = it->second->second;
        ls.splice(ls.end(), ls, it->second);
        mp[key] = --ls.end();
        return val;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it == mp.end())
        {
            if(ls.size() == m_capacity)
            {
                mp.erase(ls.begin()->first);
                ls.erase(ls.begin());
            }
            ls.push_back({key, value});
            mp[key] = --ls.end();
            return;
        }
        ls.erase(it->second);
        ls.push_back({key, value});
        mp[key] = --ls.end();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */