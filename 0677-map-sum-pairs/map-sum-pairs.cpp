using ll = long long;
struct Node
{
    Node* child[26];
    int count{0};
    Node()
    {
        fill(begin(child), end(child), nullptr);
    }
};

class MapSum {
public:
    Node* root;
    map<string, int> cnt;
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* cur = root;
        for(auto x : key)
        {
            if(cur->child[x - 'a'])
            {
                cur = cur->child[x - 'a'];
                cur->count += (val - cnt[key]);
            }
            else
            {
                cur->child[x - 'a'] = new Node();
                cur = cur->child[x - 'a'];
                cur->count += (val - cnt[key]);
            }
        }
        cnt[key] = val;
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for(auto x : prefix)
        {
            if(cur->child[x - 'a'])
            {
                cur = cur->child[x - 'a'];
            }
            else
            {
                return 0;
            }
        }

        return cur->count;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */