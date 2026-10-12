class LFUCache {
public:
    using ll = int;
    ll m_capacity;
    unordered_map<ll, list<array<ll, 3>>> freq; // [key, value, freq]
    unordered_map<ll, list<array<ll, 3>> :: iterator> ptr;
    ll min_capacity;
    LFUCache(int capacity) : m_capacity{capacity}, min_capacity{1} {
    
    }
    
    int get(int key) {
        auto it = ptr.find(key);
        if(it != ptr.end())
        {
            auto [key, value, fre] = *it->second;
            freq[fre].erase(it->second);
            freq[fre + 1].push_back({key, value, fre + 1});
            ptr[key] = --freq[fre + 1].end();
            if(min_capacity == fre && freq[fre].empty())    min_capacity++;
            return value;
        }
        return -1;
    }
    
    void put(int key, int val) {
        auto it = ptr.find(key);
        if(it != ptr.end())
        {
            auto [key, value, fre] = *it->second;
            freq[fre].erase(it->second);
            freq[fre + 1].push_back({key, val, fre + 1});
            ptr[key] = --freq[fre + 1].end();
            if(min_capacity == fre && freq[fre].empty())    min_capacity++;
            return;
        }
        ll cur = ptr.size();
        if(cur == m_capacity)
        {
            auto [key, value, fre] = freq[min_capacity].front();
            ptr.erase(key);
            freq[min_capacity].pop_front();
        }
        freq[1].push_back({key, val, 1});
        ptr[key] = --freq[1].end();
        min_capacity = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */